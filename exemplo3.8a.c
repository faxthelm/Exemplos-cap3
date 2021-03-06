#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

#define PORT 5678

int main(int argc, char *argv[])
/*
**
Listing3.8a.c - sends UDP datagrams to a remote server
*/
{
struct sockaddr_in sock;
struct hostent *hp;
int port = PORT;
int fd;

char buffer[80];
/* server */
if(argc < 2)
{
printf("\n\tUsage: %s <IP_Addr>\n\n", argv[0]);
exit(-1);
}
/* get vitals regarding remote server */
strncpy(buffer, argv[1], sizeof(buffer));
if((hp = gethostbyname(buffer)) == NULL)
{
perror("client: gethostbyname()");
exit(-1);
}
/* establish and initialize the UDP socket */
if((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
{
perror("client: socket()");
exit(-1);
}
memset((char *) &sock, 0, sizeof(sock));
memcpy(&sock.sin_addr, hp->h_addr,
hp->h_length);
sock.sin_family = hp->h_addrtype;
sock.sin_port = htons(port);
/* send a message typed from interactive user to remote server */
while(1)
{
printf("\nEnter a message: ");
fflush(stdout);
fgets(buffer, sizeof(buffer), stdin);
sendto(fd, buffer, strlen(buffer)+1, 0,
(struct sockaddr *) &sock, sizeof(sock));
if(strncmp(buffer, "EXIT", 4) == 0)
{
close(fd);
break;
}
}
puts("Bye!");
return(0);
}

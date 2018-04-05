#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 5678
int main()
{
/*
**
Listing3.8c.c - service: prints UDP datagrams from a remote client
*/

struct sockaddr_in sock;
int len=sizeof(sock);
struct hostent *hp;
int port = PORT;
int fd;
FILE *log;
char buffer[80];

/* establish and initialize UDP socket struct */
if((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
{
perror("server: socket()");
exit(-1);
}
memset((char *) &sock, 0, sizeof(sock));
sock.sin_addr.s_addr = htonl(INADDR_ANY);
sock.sin_port = htons(port);
sock.sin_family = AF_INET;
if(bind(fd, (struct sockaddr *) &sock, len) < 0)
{
perror("server: bind()");
close(fd);
exit(-1);
}


/* open a message log file */
log = fopen("/tmp/log", "w");
/* echo messages received from client into log file */
while(1)
{
recvfrom(fd, buffer, sizeof(buffer), 0,
(struct sockaddr *) &sock, &len);
fprintf(log, "Service: %s", buffer);
if(strncmp(buffer, "EXIT", 4) == 0)
{
puts("Bye!");
break;
}
/* exit request */
}
fclose(log);
return(0);
}

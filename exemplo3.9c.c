#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 4321

int main()
/*
**
Listing3.9b.c - service: prints TCP packets from a remote client
*/
{
struct sockaddr_in sock;
int len=sizeof(sock);
struct hostent *hp;
int port = PORT;
int acc, soc;
char buffer[80];
FILE *log;

/* create server socket to accept a connection */
if((acc = socket(AF_INET, SOCK_STREAM, 0)) < 0)
{
perror("server: socket()");
exit(-1);
}
memset((char *) &sock, 0, sizeof(sock));
sock.sin_addr.s_addr = htonl(INADDR_ANY);
sock.sin_port = htons(port);
sock.sin_family = AF_INET;
if(bind(acc, (struct sockaddr *) &sock, len) < 0)
{
perror("server: bind()");
close(acc);
exit(-1);
}

/* await connection */
if(listen(acc, 5) < 0)
{
perror("server: listen()");
close(acc);
exit(-1);
}
if((soc = accept(acc, (struct sockaddr *) &sock, &len)) < 0)
{
perror("server: accept()");
close(acc);
exit(-1);
}
/* open a message log file */
log = fopen("/tmp/logtcp", "w");
/* echo messages received from client into log file */
while(1)
{
recv(soc, buffer, sizeof(buffer),0);
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

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
/*
Listing3.2b.c - child: subtasking using fork() and execl()
*/
{
/* Child task sends a process id message to the screen */
printf("Child task active as process %d.\n", getpid());
/* Child task exits normally */
exit(0);
return 0;
}

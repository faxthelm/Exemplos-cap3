#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
/*
**
Listing3.1.c - single module subtasking using fork()
*/
{
int pid;
/* child task’s process id */
/* Parent task sends a process id message to the screen */
printf("\nParent task active as process %d.\n", getpid());
/* fork() creates an identical copy of the parent task */
if((pid = fork()) == 0)
{
/* This block is ONLY executed by the subtask */
/* Child task sends a process id message to the screen */
printf("Child task active as process %d.\n", getpid());
/* Child task exits normally */
exit(0);
}
/* Parent awaits child task exit */
waitpid(pid,NULL,0);
return 0;
}

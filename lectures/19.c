#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <string.h>

int main(void)
{

    int fd[2];
    if (pipe(fd) == -1)
    {
        return(1);
    }

    int pid1 = fork();
    if (pid1 == -1)
    {
        return(2);
    }
    
    if (pid1 == 0)
    {
        //Child process 1 (for ping)
        dup2(fd[1],STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);   //Already recreated to STDOUT so we won't use fd[1(write)]
        execlp("ping","ping","-c","5","google.com",NULL);
    }

    int pid2 = fork();
    if (pid2 == -1)
    {
        return(3);
    }
    
    if (pid2 == 0)
    {
        /*Grep part will be in here*/
        dup2(fd[0],STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);
        execlp("grep","grep","rtt",NULL);
    }
    
    close(fd[0]);
    close(fd[1]);
    
    waitpid(pid1,NULL,0);    
    waitpid(pid2,NULL,0);



    return(0);
}
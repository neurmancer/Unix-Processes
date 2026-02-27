#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{

    int fd[3][2];

    for (int i = 0; i < 3; i++)
    {
        if (pipe(fd[i]) < 0)
        {
            return(-2);
        }
        
    }
    

    int pid1 = fork();
    if (pid1 == -1) {return(-1); }
    


    return(0);
}
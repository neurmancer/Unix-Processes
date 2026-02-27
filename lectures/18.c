#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int main(void)
{
    int fd[2];
    if (pipe(fd) == -1) { return(-1); }

    int pid = fork();
    if (pid < 0)
    {
        return(-2);
    }
    
    if (pid == 0)
    {
        close(fd[0]);
        char str[100];
        printf("Input string: ");
        fgets(str,100,stdin);
        str[strlen(str) - 1] = '\0';
        int textSize = strlen(str)+1;

        if (write(fd[1],&textSize,sizeof(int)) == -1)
        {
            return(-4);
        }

        if (write(fd[1],str,sizeof(char)*textSize) == -1)
        {
            return(-3);
        }
    }

    else
    {
        close(fd[1]);
        char str[100];
        int textSize = 0;
        if (read(fd[0],&textSize,sizeof(int)) == -1)
        {
            return(-5);
        }
    
        if(read(fd[0],str,sizeof(char)*textSize) == -1)
        {
            return(-6);
        }
        printf("Received: %s\n",str);
        wait(NULL);
    }



    return(0);
}
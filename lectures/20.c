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
    
    if (pid1 == 0)
    {
        /* Child P 1*/
        close(fd[0][1]);
        close(fd[1][0]);
        close(fd[2][0]);
        close(fd[2][1]);

        int x;
        if(read(fd[0][0],&x,sizeof(x)) == -1) { return(-3); }
        x+=5;

        if (write(fd[1][1],&x,sizeof(x)) == -1)
        {
            return(-5);
        }
        close(fd[0][0]);
        close(fd[1][1]);
        return(0); //End child p here
    }

    int pid2 = fork();
    if (pid2 == -1)
    {
        return(-11);
    }
    
    if (pid2 == 0)
    {
        /*Child P 2*/
        close(fd[0][0]);
        close(fd[0][1]);
        close(fd[1][1]);
        close(fd[2][0]);
        int x; 
        if (read(fd[1][0],&x,sizeof(x)) == -1)
        {
            return(-13);
        }
        
        x+=5;
        if (write(fd[2][1],&x,sizeof(x)) == -1)
        {
            return(-17);
        }
        close(fd[2][1]);
        close(fd[1][0]);
        return(0);
    }
    
    close(fd[0][0]);
    close(fd[1][0]);
    close(fd[1][1]);
    close(fd[2][1]);

    int x = 0;
    printf("Input a number: ");
    fflush(stdout);
    if (scanf(" %d",&x) != 1) 
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        { /*Nothing to see here just clering buffer*/}
        return(-31);
    }
    if (write(fd[0][1],&x,sizeof(int)) == -1)
    {
        return(-23);
    }
    
    if (read(fd[2][0],&x,sizeof(int)) == -1)
    {
        return(-29);
    }
    
    close(fd[2][0]);
    close(fd[0][1]);
    
    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);

    printf("Your number + 10 is: %d\n",x);
    return(0);
}
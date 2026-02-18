#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//About wait() a basic introduction again. more advanced applications will be names as 'aN.c'
// a for advanced and N is the lecture binding like 1.c is fork() and a1.c will be about also fork() 

int main(void)
{

    int pid = fork();
    int n = 0;
    if (pid == 0)
    {
        n = 1;
    }
    else
    {
        n = 6;
    }
    if (pid != 0)
    {
        wait(NULL); //I don't know why I used null for now I'll add the correct desc. when I learn
    }
    
    //This loop can be considered as UB since we can't predict which process will execute/wait or not.
    for (int i = n; i < n+5; i++)
    {
        printf("%d ",i);    
        fflush(stdout);     //buffer flush
    }
    if (pid != 0)
    {
        printf("\n");
    }

    return(0);
}
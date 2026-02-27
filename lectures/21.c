#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
    int pid1 = fork();
    if (pid1 == -1)
    {
        return(-3);
    }
    
    if (pid1 == 0)
    {
        sleep(4);
        printf("Finished execution (%d pid)\n",getpid());
        return(0);
    }
    

    int pid2 = fork();
    if (pid2 == -1)
    {
        return(-2);
    }    

    if (pid2 == 0)
    {
        sleep(1);
        printf("Finished execution (%d)\n",getpid());
        return(0);
    }

    int pid1_res = waitpid(pid1,NULL,0);
    printf("Waited for %d\n",pid1_res);
    int pid2_res = waitpid(pid2,NULL,WNOHANG);//If you pass WNOHANG instead of 0 you'll simply get 0 instead of waiting till child finishes 
    printf("Waited for %d\n",pid2_res);
    

    return(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(void)
{

    int pid = fork();
    if (pid == -1) { return(-2);}
    
    if (pid == 0)
    {
        while (1)
        {
            printf("Some output\n");
            usleep(50000);
        }
    }
    

    else
    {
        kill(pid,SIGSTOP);
        int t;
        do {
            printf("Time in seconds for execution: ");
            fflush(stdout);
            scanf(" %d",&t);
            if (t > 0)
            {
                kill(pid,SIGCONT);
                sleep(t);
                kill(pid,SIGSTOP);

            }
            
        }while (t > 0);

        kill(pid,SIGKILL);
        wait(NULL);
    }




    /*
        kill(pid,SIGSTOP); //pause exec
        sleep(1); 
        kill(pid,SIGCONT); //continue exec
        sleep(1);
        kill(pid,SIGKILL); //KILL THE CHILD (nah just 'terminate' IK it's a way sterile way to say killing)
        wait(NULL);*/
    


    return(0);
}
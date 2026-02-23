#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


void handle_sigusr1(int sig);


int answer = 0;
int main(void)
{

    int pid = fork();
    if (pid == -1) { return(-1); }

    if (pid == 0)
    {
        sleep(5);
        kill(getppid(),SIGUSR1);        //SIGUSR1 is a signal that user-defined  more info -> https://faculty.cs.niu.edu/~hutchins/csci480/signals.htm
    }
    
    else
    {
        struct sigaction sa = { 0 }; 
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1,&sa,NULL);


        printf("What is the result of 13 x 53: ");  //Yeah I love those nums deal with it
        fflush(stdout);
        scanf(" %d",&answer);
        if (answer == 689)
        {
            printf("Noice!\n");
            kill(pid, SIGTERM);
        }
        else
        {
            printf("Bro just return to primary school already :/\n");

        }
        wait(NULL);
    }    




    return(0);
}

void handle_sigusr1(int sig)
{
    if (answer == 0)
    {
        printf("\nBro that hard? Really? I mean fuck you mean you know how PCs work but not multiplication...\n");
        printf("What is the result of 13 x 53: ");
        fflush(stdout);
    }
}
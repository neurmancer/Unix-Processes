#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


void sigTSTPHandler(int sig);


int main(void)
{
;
    int pid = fork();

    if (pid == -1)
    {
        printf("Shit went sideways\n");
        exit(1);
    }
    
    if (pid == 0)
    {
        while (1)
        {
            
            int errno = execlp("ffplay", "ffplay", "-nodisp", "-autoexit", "-fflags", "nobuffer", "-flags", "low_delay", "-probesize", "32", "-analyzeduration", "0", "-strict", "experimental","https://drive.google.com/uc?export=open&id=10aiePDkX2t2XruCaFROIum9nGkQGUzth", "-loglevel", "8", NULL);
            kill(getppid(),SIGTSTP);
        }
        
    }
    else
    {
        struct sigaction sa = { 0 }; 
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &sigTSTPHandler;
        sigaction(SIGTSTP,&sa,NULL);
        printf("Now you do get rickrolled bitch\n");
        printf("Ctrl+Z to pause tho\n");


        wait(NULL);

    }





    return(0);
}

void sigTSTPHandler(int sig)
{
    printf("\nMusic stopped press Ctrl+D to continue\n");
    int c = getchar();
    if (c == EOF)
    {
        kill(0,SIGCONT);
    }
    while (c != '\n' && c != EOF) { c++;}

}

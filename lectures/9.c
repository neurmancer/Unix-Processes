#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


int main(void)
{
    
    int pid = fork();
    if (pid == -1) {return(-1);}
    
    if (pid == 0)
    {
        execlp("ping","ping", "google.com", "-c","3",NULL); // That's gonna ping google 3 times
    }
    
    else{
    sleep(3);
    printf("\033[H\033[J");
    wait(NULL);
    }

    return(0);
}
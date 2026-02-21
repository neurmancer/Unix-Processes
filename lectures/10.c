#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


int main(void)
{
    //same project from 9.c

    int pid = fork();
    if (pid == -1) {return(-1);}
    
    if (pid == 0)
    {
        int err = execlp("ping","ping", "google.com", "-c","3",NULL);
        if (err == -1) {printf("Something went way sideways\n"); return(-1);} //if exec doesn't fail program won't arrive here 
    }
    
    else{

        int wstatus;    //waitStatus
        wait(&wstatus); // replaced NULL with status
        if (WIFEXITED(wstatus))
        {
            int statusCode = WEXITSTATUS(wstatus);      //return value of broken exec attempt 
            if (statusCode == 0)
            {
                printf("Program executed just fine\n");
            }
            else { printf("Something got fucked up\n");}
            
        }        
    }

    return(0);
}
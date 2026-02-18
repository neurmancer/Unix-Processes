#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*              This is gonna be about pipes (Introduction) I guess that's called IPC but IDK for Sure as I said still at my 11th day of programming don't wait miracles                      */

int main(void)
{
    //fd[0] = read
    //fd[1] = write
    int fd[2] = { };
    if (pipe(fd) == -1)       //Get array of 2 ints which are file descriptors 
    {
        printf("FUCK PIPE AIN'T OPENING\n");
    }   

    int pid = fork();       //Yeah most of the files will look like same till here since all I do is the same thing over and over with new sauces

    if (pid == 0)
    {
        close(fd[0]);       //Since we don't read shit from parent in this child p
        int x = 0; 
        printf("Input a number:");
        fflush(stdout); //Yeah,yeah get used to this I'll fucking use fflush every time before scanf unless I sat setvbuf to _IONBF 
        scanf("%d",&x);
        if(write(fd[1],&x,sizeof(int)) == -1)//writing to pipe file descriptor. basically write fd[1] address of x with a size of an int (4 bytes) of space
        {
            printf("Fuck I CAN'T WRITEEEEEEEEE\n");
            close(fd[1]);   //To be cautious
            return(-5);
        }            
        close(fd[1]);   //Close the write end of pipe...close your shit when you are done bois
    }

    else
    {
        close(fd[1]); //Closed writing end because we ain't writing shit in parent p
        int y = 0; //always declare your shit don't leave like int y; (or do but I ain't doing it)
        if (read(fd[0],&y,sizeof(int)) == -1) //read fd0 write to 'buffer' y size of 4 bytes
        {
                printf("FUCK I FORGOT HOW TO READ\n");
                close(fd[0]);   //To be cautious
                return(-13);    //Yeah I am selecting random prime numbers lulz.
        }
        close(fd[0]);
        printf("My son brought your int to me:%d\n",y);
    }

    return(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


/*
Program plan: Child process that's gonna generate rand ints 
Parent gonna take it and sum 'em all
*/


int main(void){

    int fd[2];
    if (pipe(fd) == -1){ return(-2); }

    int pid = fork();
    if (pid == -1) { return(-3); }

    if (pid == 0)
    {
        close(fd[0]);
        int n;
        int arr[10] = { };
        srand(time(NULL));
        n = (rand() % 10) + 1 ;
        printf("Generated: ");
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 11;
            printf("%d ",arr[i]);
        }
        printf("\n");
        if (write(fd[1],&n,sizeof(int)) == -1) { return(-7); }
        
        if (write(fd[1],arr,sizeof(int) * n) == -1) { return(-5); }
        close(fd[1]);
    }
    
    else
    {
        close(fd[1]);
        int arr[10];
        int n,sum = 0;
        if (read(fd[0],&n,sizeof(int)) == -1) {return(-13);} //always send the element counts before yk
        if (read(fd[0],arr,sizeof(int)* n) == -1) {return(-17);}

        for (int i = 0; i < n; i++)
        {
            printf("Recieved %d\n",arr[i]);
            sum+=arr[i];
        }
        printf("Result is: %d\n",sum);
        close(fd[0]);
        wait(NULL);
    }


    return(0);
}
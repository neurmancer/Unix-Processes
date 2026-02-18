#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

    //This is a pipe lecture the continous of the last one
    //Aim is diving the array to two so we can use 2 processes to sum up it twice as fast(or let's forkbomb so we can add all of them at the same time lol[jk please dont{and yeah I used differnet type of paranthesis to comment in a comment and this writing is self-aware}])

int main(void)
{

    int arr[] = {3,5,7,7,3,5,3,11,13,31};      //Yup primes it is 
    int arrSize = sizeof(arr)/sizeof(arr[0]);       
    int start = 0,end = 0;
    
    int fd[2] = { };
    if (pipe(fd) == -1) { return(1);} //silent suffering gang go brrr (please do not debug like that)
    
    int pid = fork();
    if (pid == -1)
    {
        return(-2);
    }
    
    if (pid == 0)
    {
        end = arrSize /2; 
    }
    else
    {
        start = arrSize/2;
        end = arrSize; 
    }
    int sum = 0;
    for (int i = start; i < end; i++)
    {
        sum+=arr[i];
    }
    
    printf("Partial Sum:%d\n",sum);

    if (pid == 0)
    {
        close(fd[0]);   //Close reading end of pipe
        write(fd[1],&sum,sizeof(sum));
        close(fd[1]);
    }
    
    else
    {
        int childMath = 0;
        close(fd[1]);
        read(fd[0],&childMath,sizeof(childMath));
        close(fd[0]);
        
        printf("Total sum : %d\n",sum+childMath);
        wait(NULL);
    }

//Still haven't killed any children 

    return(0);
}
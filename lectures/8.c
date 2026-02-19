#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>   

/*          This file is about IPC basics   (and deadlock)    */

int main(void)
{

    int p1[2]; //C->P
    int p2[2]; //P->C
    


    if (pipe(p1) == -1) { return(1); }
    if (pipe(p2) == -1) { return(-1); }
    
    int pid = fork();
    if (pid == -1){ return(2); }

    
    if (pid == 0)
    {
        p1[0];
        p2[1];

        //Child process block
        int x = 0; 
        if (read(p2[0],&x,sizeof(x)) == -1) { return(3); }
        printf("Received %d\n",x);
        x*=4;
        if (write(p1[1],&x,sizeof(x)) == -1) { return(4); }
        printf("Multiplied:%d\n",x);
        close(p1[1]);
        close(p2[0]);
    }
    
    else
    {
        p1[1];
        p2[0];
        srand(time(NULL));
        int y = rand() % 10;
        if (write(p2[1],&y,sizeof(y)) == -1) { return(5); }
        printf("%d\n",y);   //If you comment this line or delete it's gonna lock the process since the write/read interval is too short here child to read any shit.
        if (read(p1[0],&y,sizeof(int)) == -1) { return(6); }
        printf("Resut %d\n",y);
        close(p1[0]);
        close(p2[1]);
        wait(NULL);
    }



    return(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*              Process ID and Shit IDK(I am learning shit as I create those files)                              */

int main(void)
{
    int pid = fork();
    if (pid == 0)
    {
        sleep(1);   //forcing child p to terminate after parent 
        //And this fucks with things which will assign a 'temp' parent for child creating an orphan lulz not orphan actually I learned that 
        //This called zombie process if a child without parent(tho orphan is much more suitable)
    }
    if (pid != 0)
    {
        wait(NULL); //Retrun -1 if there is no child p to wait
        //Btw after 2.c I learned that this NULL thingy is a pointer that usually returns us (ofc if it's not null) the exit code of the child like if it terminated or forced to kill etc.
        //This if block forces parent to wait the sleep duration too so this will work properly again
    }

    printf("Current ID:%d,\tParent ID:%d\n",getpid(),getppid()); //PPID = Parent process ID


    return(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*                      Introduction for fork() next lecture will be about wait()           */

int main(void)
{

    int pid = fork();                 //This creates a parallel process line from this point on
    printf("hello, world!\tProcess ID:%d\n",pid);   //Child process gets 0 as the OG getting the actual ID: IMPORTANT: -1 WHEN AN ERROR OCCURS
    if (pid == 0)
    {
        printf("I've been born!\n");
    }
    else
    {
        printf("Does that mean I finally got laid somewhere in past?\n");
    }
    

    return(0);
}
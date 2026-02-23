#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
    This is a little experiment lecture with Ctrl+Z'ing scanf (which sends a SIGTSTP signal(you can think it as SIGSTOP but we can handle basically))
    and bringing it back to foreground with fg command in bash 
*/

int main(void)
{
    int x = 0;
    printf("Input number: ");
    fflush(stdout);
    scanf(" %d",&x);
    printf("Result %d * 5 = %d\n",x,x*5);


    return(0);
}
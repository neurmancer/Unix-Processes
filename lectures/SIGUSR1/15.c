#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void handle_sigstp(int sig)
{
    printf("\nYou ain't pausing shit lulz\n");
}

/*
    Starting with same script in 14.c and we'll see sig handling
*/

int main(void)
{
    /*Honest take tho just use signal() bro...
    btw I am fucking with you, learn sigaction instead for compatibility reasons etc. 
    https://man7.org/linux/man-pages/man2/signal.2.html <- Here is why nerds
    */

    struct sigaction sa;        //It does work but for some reason intellisense marks it as 'Wrong/Incorrect' so morale of the story: Use fucking vim.
    sa.sa_handler = &handle_sigstp;
    sa.sa_flags = SA_RESTART; 
    sigaction(SIGTSTP,&sa,NULL);
    int x = 0;
    printf("Input number: ");
    fflush(stdout);
    scanf(" %d",&x);
    printf("Result %d * 5 = %d\n",x,x*5);


    return(0);
}
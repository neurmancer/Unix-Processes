#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

//This file gonna write things to 'sum' and the 7-2.c will be the one which reads from the 'sum' file 
//So if you encounter this lecture on github open both neither of them work alone and will just hang open idle (said )

int main(void)
{
    srand(time(NULL));

    if (mkfifo("sum",0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Something fucked up happened\n");
            return(1);
        }
    } 

    int arr[5] = { };

    for (int *i = arr; i < arr+5; i++)
    {
        *i = rand() % 100;
        printf("Written %d to file\n",*i);
    }
    
    int fd = open("sum",O_WRONLY);
    if (fd == -1) { printf("Shit\n");return(1); }
 

        if (write(fd,&arr,sizeof(int)*5) == -1)
        {
            return(2);
        }
    
    close(fd); //Don't forget closing shit

    //I fucking been debugging this shit for 20+ mins just because I forgot -1s in if blocks FUCKKKKKKK 

    return(0);
}
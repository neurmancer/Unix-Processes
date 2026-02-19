#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//This is the reader file

int main(void)
{
    int arr[5] = { };
    int fd = open("sum", O_RDONLY);
    if (fd == -1)
    {
        return(1);
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        if (read(fd,arr,sizeof(int)*5) == -1) { printf("Test\n");return(2); }
        printf("%d\n",arr[i]);
        sum+=arr[i];
    }
    printf("The sum is: %d\n",sum);
    close(fd);
    
    //Like all the other files FIFOs have their buffers too note to futureself.
    return(0);
}
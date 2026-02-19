#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/errno.h>

//This is about FIFO (which is named pipes and I assume FIFO means file input, file output but haven't checked yet)



int main(void)
{
    //Second argument is privillege to write/read and 0777 (in octal) means anybody can read/write to this file

    if(mkfifo("myfifo1",0777) == -1) //if we have the file myfifo1 this will return 1 anyways since it didn't create fresh and the file have already existed
    {
        if (errno !=EEXIST) //Says if the error is file already exists don't care but if something else gets fucked sideways return(1) 
        {
            printf("Couldn't create fifo file\n");
            return(1);        
        }
    }

    int fd = open("myfifo1",O_RDWR);       //This means we opened file for both read&write and it returns file descriptor    
    
    if (fd == -1)
    {
        printf("Something bad happened :/ \n");
        return(2);
    }
    

    int x = 1353;
    if (write(fd,&x,sizeof(x)) == -1)       //This gonna hang dead since there is no one to read and FIFO waits till both ends open at the same time
    {
        return(3);
    }
    
    close(fd);      





    return(0);
}
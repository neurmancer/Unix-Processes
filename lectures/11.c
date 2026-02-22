/*Code's based on 10.c*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //got fork()
#include <time.h> 
#include <sys/wait.h> //Got wait()
#include <fcntl.h> //Got open()

/*

Basic file descriptors
0       STDIN
1       STDOUT
2       STDERR
*/


int main(void)
{
    //same project from 9.c
    int file = open("pingResults.txt",O_WRONLY | O_CREAT,0777); // 0777(511 in decimal 7*8^2+7*8^1+7*8^0) in octal means accessable to every file 
    /*When you open a file it gets a file descriptors ID like the STDOUT/IN and depending on architecture of OSs 
    it usually tends to get lowest number available so in our case 3 
    (right after STDERR) and if you were to close(STDOUT) (or 1) probably next open will get 1 instead
    if not taken by another process before
    */ 

    if (file == -1) { return(-1);} 

    int file2 = dup2(file,STDOUT_FILENO);      //returns anoter file descrp to the given int(1 and STDOUT_FILENO are the same). AND closes the file in that addres first
    
    close(file);        //Since we don't use the OG id we close it


    int pid = fork();
    if (pid == -1) {return(-1);}
    
    if (pid == 0)
    {
        int err = execlp("ping","ping", "google.com", "-c","3",NULL);
        if (err == -1) {printf("Something went way sideways\n"); return(-1);} //if exec doesn't fail program won't arrive here 
    }
    
    else{

        int wstatus;    //waitStatus
        wait(&wstatus); // replaced NULL with status
        if (WIFEXITED(wstatus))
        {
            int statusCode = WEXITSTATUS(wstatus);      //return value of broken exec attempt 
            if (statusCode == 0)
            {
                printf("Program executed just fine\n");
            }
            else { printf("Something got fucked up\n");}
            
        }        
    }

    return(0);
}
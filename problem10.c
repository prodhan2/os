#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
 int main()
 {


    char buffer[1000];
    pid_t pid = fork();

if(pid >0)
{
     //parent process 
     printf("Type e message ... \n");
     read(0, buffer , sizeof(buffer));
     fflush(stdout);

     int fd = open("ten", O_WRONLY);

     write(fd, buffer, sizeof(buffer));
  close(fd);

}
    else
    {

        //child process 
        int fd  = open("ten" , O_RDONLY);
        read(fd,buffer , sizeof(buffer));

        printf("Message  recived succefulyy  .. : %s " , buffer);
        close(fd);


    }
    
 }
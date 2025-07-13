#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/wait.h>

struct msg_buffer 
{
   long type;
   char text[1000];
};

int main()
{

   struct  msg_buffer msg ;
   key_t key = 1234;
   int msgid = msgget(key , 0666 | IPC_CREAT);
 
 pid_t pid = fork();
if(pid == 0)
{

    //child process 
    printf("Enter e message ... \n");
    msg.type = 1;
    fgets(msg.text , sizeof(msg.text),stdin);
    msgsnd(msgid, &msg , sizeof(msg.text),0);
}

else if (pid >0)
{
    

       
        int status ;
        wait(&status);

   
    msgrcv(msgid , &msg , sizeof(msg.text),1,0);

    printf("MEssage recived succefulyy ..  : %s \n", msg.text);

    msgctl(msgid, IPC_RMID , NULL);
}

}
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int counter =0;
void* increment(void* arg)
{
for(int i =0;i<100000;i++)
{
    counter ++;
}
return NULL;
}

int main()
{

    pthread_t p1,p2;

    pthread_create(&p1, NULL , increment , NULL);
    pthread_create(&p2 , NULL ,  increment , NULL);

    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    printf("Expected :   200000  but actual : %d" , counter);
    //race conditions here coccur...
}
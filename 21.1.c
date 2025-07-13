#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int n ;
int *fibo;

void* fibo_generator (void* arg)
{

    if(n>0) fibo[0] = 0;
    if(n>1) fibo[1] = 1;
    for (int i =2;i<n;i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    pthread_exit(NULL);
}


int main()
{

    pthread_t p1 ;
    printf("How many fibonnacci ... \n");
    scanf("%d", &n);
    fibo = (int*) malloc(n*sizeof(int));

    pthread_create(&p1,NULL,fibo_generator,NULL);
    pthread_join(p1,NULL);

   printf("Fibonnaci numbers are .. \n");
   for (int i =0;i<n;i++)
   {
    printf("%d " , fibo[i]);
   }
   printf("\n");

}
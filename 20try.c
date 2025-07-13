#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int *values;
int n ;
int maxValue =0,minValue =0 ;
double avg =0.0;

void*  avgcal (void *agr)
{
    int sum =0;
    for (int i =0;i<n;i++)
    {
        sum += values[i];

    }
    avg = (double) sum/n;
    return NULL;

}

void* maxcal (void *agr)
{
    maxValue = values[0];

    for(int i=1;i<n;i++)
    {
        if(values[i] >maxValue) maxValue = values[i];
    }
    return NULL;


}


void* mincal (void *agr)
{
    minValue = values[0];

    for(int i=1;i<n;i++)
    {
        if(values[i] <minValue) minValue = values[i];
    }
    return NULL;
    
}


 int main(int agrc , char *argv[])
 { 
    pthread_t p1 ,p2,p3;

    if(agrc <2) {
        printf("error");
        return 1;
    }

    
    n = agrc -1;
    values = malloc(n*sizeof(int));
    for (int  i = 0; i < n; i++)
    {
       values [i] = atoi(argv[i+1]); 
    }
    
    pthread_create(&p1, NULL , mincal , NULL);
    pthread_create(&p2 ,NULL,  maxcal, NULL);
    pthread_create(&p3,NULL , avgcal , NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    printf("Average = %.2lf\n", avg);
printf("Maximum = %d\n", maxValue);
printf("Minimum = %d\n", minValue);


    free(values);
    return 0;
   

 }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include "Tutorial.h"

enum response_type {NO, YES};
void* does_not(void *a)
{
    int i=0;
    for(i=0;i<5;i++)
    {
        sleep(1);
        puts("No!\n");
    }
    return NULL;
}

void* does_too(void *a)
{
    int i=0;
    for(i=0;i<5;i++)
    {
        sleep(1);
        puts("Yes!\n");
    }
    return NULL;
}

void error(char *msg)
{
    fprintf(stderr,"%s: %s\n",msg,strerror(errno));
    exit(1);
}
void(*functions[])(void *a) = {does_not, does_too};
void potock()
{
    pthread_t t0;
    pthread_t t1;
    if(pthread_create(&t0,NULL,does_not,NULL)==-1)
        error("Unable to create a thread t0\n");
    if(pthread_create(&t1,NULL,does_too,NULL)==-1)
        error("Unable to create a thread t1\n");
    void *result;
    if(pthread_join(t0,&result)==-1)
        error("Can't join thread t0\n");
    if(pthread_join(t1,&result)==-1)
        error("Can't join thread t1\n");
}
int beers = 2000000;

pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER; 
void* drink_lots(void *a)
{
 int i;
 pthread_mutex_lock(&beers_lock);
 for (i = 0; i < 100000; i++) {
 beers = beers - 1;
 }
 pthread_mutex_unlock(&beers_lock);
 printf("beers = %i\n", beers);
 return NULL;
}
void piwo()
{
    pthread_t threads[20];
    int t;
    printf("%d bottles of beer are on the wall, %d bottles of beer\n",beers,beers);
    for(t=0;t<20;t++)
    {
        pthread_create(&threads[t],NULL,drink_lots,NULL);
    }
    void *result;
    for(t=0;t<20;t++)
    {
        pthread_join(threads[t],&result);
    }
    printf("Now %d bottles of beers are left on the wall\n",beers);
}
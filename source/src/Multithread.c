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

void potock()
{
    pthread_t thread_one, thread_two, thread_three; 
    printf("Before Thread\n"); 
    pthread_create(&thread_one, NULL, foo, NULL); //the foo function from Tutorial.h file
    pthread_join(thread_one, NULL); 
    pthread_create(&thread_two, NULL, preprocessor, NULL); //the preprocessor function from Tutorial.h file
    pthread_join(thread_two, NULL); 
    pthread_create(&thread_three, NULL, test, NULL); //the test function from Tutorial.h file
    pthread_join(thread_three, NULL); 
    printf("After Thread\n"); 
    exit(0); 
}

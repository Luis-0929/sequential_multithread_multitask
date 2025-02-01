#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

void* childThread(void *i){
    int* j = (int*)malloc(sizeof(int));
    *j = 5;
    printf("This is the child thread!, %d\n", *((int *)i));
    pthread_exit((void*)j);
}

int main(int argc, char *argv[]) {
    
    int send = 15; 
    int* recive = NULL; 

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, childThread, (void*)&send); // Creates the thread with the pointer to thread, setting odf the thread, the pointer to the funciton that the thread will execute, and argumentrs you want to pass into the function
    pthread_join(thread_id, (void**)&recive); // Tells the main function to wait for the thread to finish, second argument is the return value of the fucntion if there is one
    printf("%d\n", *recive); 
}
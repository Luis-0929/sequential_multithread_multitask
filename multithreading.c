#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

void print_int128(__int128 num) {
    if (num > 9) {
        print_int128(num / 10);
    }
    putchar('0' + (num % 10));
}

// void* childThread(void *i){
//     int* j = (int*)malloc(sizeof(int));
//     *j = 5;
//     printf("This is the child thread!, %d\n", *((int *)i));
//     pthread_exit((void*)j);
// }
void* childThread() {
    unsigned __int128* sum = (unsigned __int128*)malloc(sizeof(unsigned __int128));
    *sum = 0;
    unsigned long long n = 1000000000;

    for(unsigned long long i = 0; i < (n / 2); i++){
        *sum+=i;
    }
    //printf("The child thread is sending back the sum of %llu\n", *((unsigned __int128 *)sum));
    pthread_exit((void*)sum);
}

int main(int argc, char *argv[]) {
    
    // int send = 15; 
    // int* recive = NULL; 

    // pthread_t thread_id;
    // pthread_create(&thread_id, NULL, childThread, (void*)&send); // Creates the thread with the pointer to thread, setting odf the thread, the pointer to the funciton that the thread will execute, and argumentrs you want to pass into the function
    // pthread_join(thread_id, (void**)&recive); // Tells the main function to wait for the thread to finish, second argument is the return value of the fucntion if there is one
    // printf("%d\n", *recive); 
    clock_t start, end;
    unsigned __int128* child_sum = NULL;
    pthread_t thread_id;
    start = clock();
    pthread_create(&thread_id, NULL, childThread, NULL);

    
    
    unsigned __int128 main_sum = 0;
    unsigned long long num = 1000000000;
    

    for(unsigned long long i = (num / 2); i < num; i++){
        main_sum+=i;
    }
    pthread_join(thread_id, (void**)&child_sum);

    end = clock();
    double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    unsigned __int128 final_sum = main_sum + *child_sum;
    // printf("main sum is %llu\n", main_sum);
    // printf("final sum is %llu\n", final_sum);

    print_int128(final_sum);
    printf("\n");
    printf("elapsed time was %.10f\n",elapsed);







}
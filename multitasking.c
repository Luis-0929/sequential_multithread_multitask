#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/wait.h>

  
// 100000000

 


int main(int argc, char *argv[]) {
    uint64_t n = atoll(argv[1]);
    int tasks = atoi(argv[2]);
    printf("Received workload of %llu with %d tasks...starting...\n", n, tasks); 

    // for(int i = 0; i < tasks; i++){
    //     int pid = fork(); 
    // }


}
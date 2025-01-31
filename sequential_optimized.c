#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

void print_int128(__int128 num) {
    if (num > 9) {
        print_int128(num / 10);
    }
    putchar('0' + (num % 10));
}


int main(int argc, char *argv[]) {
    clock_t start, end;
    unsigned long long n = atoll(argv[1]);
    unsigned __int128 sum = 0;

    start = clock();
    for(unsigned long long i = 0; i < n; i++) {
        sum += i;
    }
    end = clock();
    double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Time elapsed for that workload was %.10f seconds and the sum was \n",elapsed);
    print_int128(sum);
    printf("\n");

    return 0; 
}
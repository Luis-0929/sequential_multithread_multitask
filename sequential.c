#include <stdio.h>
#include <time.h>
#include <stdint.h>


void print_int128(__int128 num) {
    if (num > 9) {
        print_int128(num / 10);
    }
    putchar('0' + (num % 10));
}

int main() {
    clock_t start, end;
    long long int n_1 = 100000000;
    long long int n_2 = 1000000000; 
    long long int n_3 = 10000000000;
    
    long long int sum_1 = 0;
    long long int sum_2 = 0; 
    __int128 sum_3 = 0;



    start = clock();
    for(int i = 0; i < n_1; i++) {
        sum_1 += i;
    }
    end = clock();
    double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("The sum of n is %lld and the time elapsed for that workload was %.10f seconds\n", sum_1, elapsed);


    start = clock();
    for(int i = 0; i < n_2; i++) {
        sum_2 += i;
    }
    end = clock();
    elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("The sum of n_2 is %lld and the time elapsed for that workload was %.10f seconds\n", sum_2, elapsed);
    



    start = clock();
    for(__int128 i = 0; i < n_3; i++) {
         sum_3 += i;
    }
    end = clock();
    elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("The sum of n_3 is "); print_int128(sum_3); printf(" and the time elapsed for that workload was %.10f seconds\n", elapsed);

    return 0;
}

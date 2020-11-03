#include "row-threaded.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

const int **M1, **M2; 
int **M3; 
int m, n; 


void run_row_threads(const int **A, const int **B, int **C, const int L, const int M, const int N) {
    M1 = A;
    M2 = B;
    M3 = C;
    m = M;
    n = N;
    pthread_t row_thread[L];
    for (int i = 0; i < L; i++) 
        if (pthread_create(&row_thread[i], NULL, compute_row, (void *) (intptr_t) i)) {
            printf("COULD NOT CREATE A ROW THREAD!\n");
            exit(1);
        }
    for (int i = 0; i < L; i++) 
        pthread_join(row_thread[i], NULL);
}

void *compute_row(void *row) {
    int i = (int) row;
    for (int k = 0; k < n; k++)
        for (int j = 0; j < m; j++)
            M3[i][k] += M1[i][j] * M2[j][k];
}

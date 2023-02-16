#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main() {
    int i, j, k, chunk_size;
    double start_time, end_time;
    double A[SIZE][SIZE],B[SIZE][SIZE],C[SIZE][SIZE];
    // double **A, **B, **C;
    // A = (double **) malloc(SIZE * sizeof(double *));
    // B = (double **) malloc(SIZE * sizeof(double *));
    // C = (double **) malloc(SIZE * sizeof(double *));

    // for (i = 0; i < SIZE; i++) {
    //     A[i] = (double *) malloc(SIZE * sizeof(double));
    //     B[i] = (double *) malloc(SIZE * sizeof(double));
    //     C[i] = (double *) malloc(SIZE * sizeof(double));
    // }

    // Initialize matrices A and B
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    chunk_size = 25;

    // Static scheduling
    start_time = omp_get_wtime();
    #pragma omp parallel for shared(A, B, C) private(i, j, k) schedule(static, chunk_size)
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end_time = omp_get_wtime();
    printf("Static scheduling time: %f seconds\n", end_time - start_time);

    // Dynamic scheduling
    start_time = omp_get_wtime();
    #pragma omp parallel for shared(A, B, C) private(i, j, k) schedule(dynamic, chunk_size)
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end_time = omp_get_wtime();
    printf("Dynamic scheduling time: %f seconds\n", end_time - start_time);

    // Guided scheduling
    start_time = omp_get_wtime();
    #pragma omp parallel for shared(A, B, C) private(i, j, k) schedule(guided, chunk_size)
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end_time = omp_get_wtime();
    printf("Guided scheduling time: %f seconds\n", end_time - start_time);

    // Free memory
    // for (i = 0; i < SIZE; i++) {
    //     free(A[i]);
    // }
}

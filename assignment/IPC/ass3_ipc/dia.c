#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h> 

void spmv_dia_omp(const int* offsets, const double* data, const double* x, double* y, int n, int ndiags) {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < ndiags; j++) {
            int k = i + offsets[j];
            if (k >= 0 && k < n) {
                sum += data[j*n+i] * x[k];
            }
        }
        y[i] = sum;
    }
}

int main() {
    
    const int n     =   100000;
    const int ndiags   =   500;

    // Generate a random sparse matrix in DIA format
    int* offsets = malloc(ndiags * sizeof(int));
    double* data = malloc(ndiags * n * sizeof(double));
    for (int i = 0; i < ndiags; i++) {
        offsets[i] = (rand() % (2*n-1)) - n + 1;
        for (int j = 0; j < n; j++) {
            data[i*n+j] = (double)rand() / RAND_MAX;
        }
    }

    // Generate a random dense vector
    double* x = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        x[i] = (double)rand() / RAND_MAX;
    }

    // Compute SpMV using sequential DIA format
    double* y_seq = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        y_seq[i] = 0.0;
    }
    double t1 = omp_get_wtime();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ndiags; j++) {
            int k = i + offsets[j];
            if (k >= 0 && k < n) {
                y_seq[i] += data[j*n+i] * x[k];
            }
        }
    }
    double t2 = omp_get_wtime();
    double elapsed_seq = t2 - t1;

    // Compute SpMV using OpenMP DIA format
    double* y_omp = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        y_omp[i] = 0.0;
    }
    t1 = omp_get_wtime();
    spmv_dia_omp(offsets, data, x, y_omp, n, ndiags);
    t2 = omp_get_wtime();
    double elapsed_omp = t2 - t1;

    // Compare the results
    for (int i = 0; i < n; i++) {
        if (fabs(y_seq[i] - y_omp[i]) > 1e-5) {
            fprintf(stderr, "Error: mismatch at index %d\n", i);
            return 1;
        }
    }

    int num = 10;
    printf("first %d values : \n", num);

    for (int i = 0; i < num; i++) {
        printf("%lf ", y_seq[i]);
    }
    printf("\n");

    for (int i = 0; i < num; i++) {
        printf("%lf ", y_omp[i]);
    }
    printf("\n");

    // Print the performance results
    printf("Sequential COO: %lf s\n", elapsed_seq);
    printf("OpenMP COO: %lf s\n", elapsed_omp);
    printf("Speedup = %lf \n", elapsed_seq/elapsed_omp);

    return 0;
}

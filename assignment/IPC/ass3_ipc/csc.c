#include <stdio.h>
#include <stdlib.h>
#include <omp.h> 
#include <math.h>

void spmv_csc_seq(const int* col_ptr, const int* row_idx, const double* data, const double* x, double* y, int n) {
    for (int j = 0; j < n; j++) {
        double sum = 0.0;
        for (int k = col_ptr[j]; k < col_ptr[j+1]; k++) {
            int i = row_idx[k];
            double val = data[k];
            sum += val * x[i];
        }
        y[j] = sum;
    }
}

void spmv_csc_omp(const int* col_ptr, const int* row_idx, const double* data, const double* x, double* y, int n) {
    #pragma omp parallel for
    for (int j = 0; j < n; j++) {
        double sum = 0.0;
        for (int k = col_ptr[j]; k < col_ptr[j+1]; k++) {
            int i = row_idx[k];
            double val = data[k];
            sum += val * x[i];
        }
        y[j] = sum;
    }
}

int main() {
    const int n     =   1000000;
    const int nnz   =   5000000;

    // Generate a random sparse matrix in CSC format
    int* col_ptr = malloc((n+1) * sizeof(int));
    int* row_idx = malloc(nnz * sizeof(int));
    double* data = malloc(nnz * sizeof(double));
    col_ptr[0] = 0;
    for (int j = 0; j < n; j++) {
        int nnz_j = 0;
        for (int i = 0; i < nnz/n; i++) {
            int k = rand() % n;
            double val = (double)rand() / RAND_MAX;
            row_idx[col_ptr[j] + nnz_j] = k;
            data[col_ptr[j] + nnz_j] = val;
            nnz_j++;
        }
        col_ptr[j+1] = col_ptr[j] + nnz_j;
    }

    // Generate a random dense vector
    double* x = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        x[i] = (double)rand() / RAND_MAX;
    }

    // Compute SpMV using sequential CSC format
    double* y_seq = malloc(n * sizeof(double));
    spmv_csc_seq(col_ptr, row_idx, data, x, y_seq, n);
    double t1 = omp_get_wtime();
    spmv_csc_seq(col_ptr, row_idx, data, x, y_seq, n);
    double t2 = omp_get_wtime();
    double elapsed_seq = t2 - t1;

    // Compute SpMV using OpenMP CSC format
    double* y_omp = malloc(n * sizeof(double));
    spmv_csc_omp(col_ptr, row_idx, data, x, y_omp, n);
    t1 = omp_get_wtime();
    spmv_csc_omp(col_ptr, row_idx, data, x, y_omp, n);
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
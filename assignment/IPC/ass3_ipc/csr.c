#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h> 

void spmv_csr_seq(const int* row_ptr, const int* col_idx, const double* data, const double* x, double* y, int n) {
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int k = row_ptr[i]; k < row_ptr[i+1]; k++) {
            int j = col_idx[k];
            double val = data[k];
            sum += val * x[j];
        }
        y[i] = sum;
    }
}

void spmv_csr_omp(const int* row_ptr, const int* col_idx, const double* data, const double* x, double* y, int n) {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int k = row_ptr[i]; k < row_ptr[i+1]; k++) {
            int j = col_idx[k];
            double val = data[k];
            sum += val * x[j];
        }
        y[i] = sum;
    }
}

int main() {
    
    const int n     =   1000000;
    const int nnz   =   5000000;

    // Generate a random sparse matrix in CSR format
    int* row_ptr = malloc((n+1) * sizeof(int));
    int* col_idx = malloc(nnz * sizeof(int));
    double* data = malloc(nnz * sizeof(double));
    row_ptr[0] = 0;
    for (int i = 0; i < n; i++) {
        int nnz_i = 0;
        for (int j = 0; j < nnz/n; j++) {
            int k = rand() % n;
            double val = (double)rand() / RAND_MAX;
            col_idx[row_ptr[i] + nnz_i] = k;
            data[row_ptr[i] + nnz_i] = val;
            nnz_i++;
        }
        row_ptr[i+1] = row_ptr[i] + nnz_i;
    }

    // Generate a random dense vector
    double* x = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        x[i] = (double)rand() / RAND_MAX;
    }

    // Compute SpMV using sequential CSR format
    double* y_seq = malloc(n * sizeof(double));
    spmv_csr_seq(row_ptr, col_idx, data, x, y_seq, n);
    double t1 = omp_get_wtime();
    spmv_csr_seq(row_ptr, col_idx, data, x, y_seq, n);
    double t2 = omp_get_wtime();
    double elapsed_seq = t2 - t1;

    // Compute SpMV using OpenMP CSR format
    double* y_omp = malloc(n * sizeof(double));
    spmv_csr_omp(row_ptr, col_idx, data, x, y_omp, n);
    t1 = omp_get_wtime();
    spmv_csr_omp(row_ptr, col_idx, data, x, y_omp, n);
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

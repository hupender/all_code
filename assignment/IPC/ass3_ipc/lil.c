#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h> 

typedef struct {
    int* indices;
    double* data;
    int nnz;
} lil_row_t;

void spmv_lil_omp(const lil_row_t* rows, const double* x, double* y, int n) {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < rows[i].nnz; j++) {
            int k = rows[i].indices[j];
            sum += rows[i].data[j] * x[k];
        }
        y[i] = sum;
    }
}

int main() {
    
    // 1e5, 5*1e4 => speedup 3
    const int n     =   100000;
    const int nnz   =   50000; // per row

    // Generate a random sparse matrix in LIL format
    lil_row_t* rows = malloc(n * sizeof(lil_row_t));
    for (int i = 0; i < n; i++) {
        rows[i].indices = malloc(nnz * sizeof(int));
        rows[i].data = malloc(nnz * sizeof(double));
        rows[i].nnz = 0;
    }
    for (int k = 0; k < nnz; k++) {
        int i = rand() % n;
        int j = rand() % n;
        double val = (double)rand() / RAND_MAX;
        rows[i].indices[rows[i].nnz] = j;
        rows[i].data[rows[i].nnz] = val;
        rows[i].nnz++;
    }

    // Generate a random dense vector
    double* x = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        x[i] = (double)rand() / RAND_MAX;
    }

    // Compute SpMV using sequential LIL format
    double* y_seq = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        y_seq[i] = 0.0;
        for (int j = 0; j < rows[i].nnz; j++) {
            int k = rows[i].indices[j];
            double val = rows[i].data[j];
            y_seq[i] += val * x[k];
        }
    }
    double t1 = omp_get_wtime();
    for (int i = 0; i < n; i++) {
        y_seq[i] = 0.0;
        for (int j = 0; j < rows[i].nnz; j++) {
            int k = rows[i].indices[j];
            double val = rows[i].data[j];
            y_seq[i] += val * x[k];
        }
    }
    double t2 = omp_get_wtime();
    double elapsed_seq = t2 - t1;

    // Compute SpMV using OpenMP LIL format
    double* y_omp = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        y_omp[i] = 0.0;
    }
    t1 = omp_get_wtime();
    spmv_lil_omp(rows, x, y_omp, n);
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

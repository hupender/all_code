#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>


#define N 50000000

int main() {
    
    struct timeval tv1, tv2;
    struct timezone tz;
	double serial_elapsed, parallel_elapsed; 
    int i;
    double dot_prod = 0.0;
    
    double* A = (double*) malloc(N * sizeof(double));
    double* B = (double*) malloc(N * sizeof(double));

    // initialize A and B arrays
    for (i = 0; i < N; i++) {
        A[i] = i * 1.0;
        B[i] = i * 2.0;
    }

    // serial version of dot product
    gettimeofday(&tv1, &tz);
    for (i = 0; i < N; i++) {
        dot_prod += A[i] * B[i];
    }
    gettimeofday(&tv2, &tz);

    serial_elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    printf("dot product: %.2f\n", dot_prod);
    
    printf("elapsed serial time = %f seconds.\n", serial_elapsed);

   
    dot_prod = 0.0;

    omp_set_num_threads(omp_get_num_procs());
    gettimeofday(&tv1, &tz);

    #pragma omp parallel for reduction(+:dot_prod) schedule(static)
    for (i = 0; i < N; i++) {    
        dot_prod += (A[i] * B[i]);
    }
    
    gettimeofday(&tv2, &tz);
    parallel_elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    printf("elapsed parallel time = %f seconds.\n", parallel_elapsed);


    
    printf("Speedup is %f", serial_elapsed/parallel_elapsed);

    free(A);
    free(B);

    return 0;
}
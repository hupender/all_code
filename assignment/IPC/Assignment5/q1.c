#include <stdio.h>
#include <omp.h>
#include<stdlib.h>

#define INF 99999

int main() {
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            graph[i][j]=rand()%100;
        }
    }

    printf("The graph enteries are : ");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    double start_time,end_time;
    int i,j,k;
    start_time=omp_get_wtime();

    #pragma omp parallel shared(graph) private(k, i, j)
    {
        #pragma omp for schedule(static)
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (graph[i][k] + graph[k][j] < graph[i][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
    end_time=omp_get_wtime();

    printf("Time taken to excecute in parallel is %f seconds \n",end_time-start_time);

    printf("The shortest distances between every pair of vertices are: \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", graph[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

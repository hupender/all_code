#include <stdio.h>
#include <mpi.h>

#define INF 99999

int main(int argc, char** argv) {
    int numprocs, myid;
    int n, i, j, k;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    printf("Process %d is alive\n", myid);

    if (myid == 0) {
        printf("Enter the number of vertices: ");
        scanf("%d", &n);
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int chunk_size = n / numprocs;
    int start = myid * chunk_size;
    int end = (myid + 1) * chunk_size;

    int graph[chunk_size][n];

    if (myid == 0) {
        printf("Enter the graph matrix (enter %d for infinity): \n", INF);

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &graph[i][j]);
            }
        }
    }

    MPI_Bcast(&graph, n*n, MPI_INT, 0, MPI_COMM_WORLD);

    #pragma omp parallel shared(graph) private(k, i, j)
    {
        #pragma omp for schedule(static)
        for (k = 0; k < n; k++) {
            for (i = start; i < end; i++) {
                for (j = 0; j < n; j++) {
                    if (graph[i-start][k] + graph[k][j] < graph[i-start][j]) {
                        graph[i-start][j] = graph[i-start][k] + graph[k][j];
                    }
                }
            }
        }
    }

    if (myid == 0) {
        int recv[chunk_size][n];
        for (i = 1; i < numprocs; i++) {
            MPI_Recv(&recv, chunk_size*n, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            for (j = 0; j < chunk_size; j++) {
                for (k = 0; k < n; k++) {
                    graph[i*chunk_size+j][k] = recv[j][k];
                }
            }
        }

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
    } else {
        MPI_Send(&graph, chunk_size*n, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}

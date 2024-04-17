#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100

void warshallsAlgorithm(int graph[MAX_SIZE][MAX_SIZE], int n) {
    int i, j, k;

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (graph[i][j] || (graph[i][k] && graph[k][j])) {
                    graph[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    int graph[MAX_SIZE][MAX_SIZE];
    int n, i, j;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    start = clock(); // Start the clock

    warshallsAlgorithm(graph, n);

    end = clock(); // Stop the clock

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The transitive closure of the graph is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
/*
sample input
Enter the number of vertices in the graph: 4
Enter the adjacency matrix of the graph:
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0
*/
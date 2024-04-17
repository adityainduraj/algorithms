#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100
#define INFINITY 9999

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    int distance[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    // Initialize distance and visited arrays
    for (int i = 0; i < numVertices; i++) {
        distance[i] = INFINITY;
        visited[i] = false;
    }

    // Distance of start vertex from itself is always 0
    distance[startVertex] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < numVertices - 1; count++) {
        int minDistance = INFINITY;
        int minIndex;

        // Find the vertex with minimum distance
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minIndex] = true;

        // Update distance values of adjacent vertices
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph[minIndex][v] && distance[minIndex] != INFINITY &&
                distance[minIndex] + graph[minIndex][v] < distance[v]) {
                distance[v] = distance[minIndex] + graph[minIndex][v];
            }
        }
    }

    // Print the shortest path distances
    printf("Shortest path distances from vertex %d:\n", startVertex);
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: %d\n", i, distance[i]);
    }
}

int main() {
    int numVertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    clock_t start = clock(); // Start the clock
    dijkstra(graph, numVertices, startVertex);
    clock_t end = clock(); // Stop the clock
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Cast the result to double
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
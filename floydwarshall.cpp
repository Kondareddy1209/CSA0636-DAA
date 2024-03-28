#include <stdio.h>
#include <limits.h>
#define V 10
void printSolution(int dist[][V], int n) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}
void floydWarshall(int graph[][V], int n) {
    int dist[V][V];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist, n);
}
int main() {
    int n;
    printf("Enter the number of vertices in the graph (maximum %d): ", V);
    scanf("%d", &n);
    int graph[V][V];
    printf("Enter the adjacency matrix representing the graph (INF for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    floydWarshall(graph, n);
    return 0;
}



output:
Enter the number of vertices in the graph (maximum 10): 4
Enter the adjacency matrix representing the graph (INF for no edge):
1 4 2 5
1 3 1 3
1 5 3 6
8 6 4 3
Shortest distances between every pair of vertices:
1       4       2       5
1       3       1       3
1       5       3       6
4       6       3       4

--------------------------------
Process exited after 23.51 seconds with return value 0
Press any key to continue . . .

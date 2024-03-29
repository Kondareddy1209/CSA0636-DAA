#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10
bool isSafe(int v, bool graph[][MAX_VERTICES], int path[], int pos, int V) {
    if (!graph[path[pos - 1]][v])
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}
bool hamiltonianCircuitUtil(bool graph[][MAX_VERTICES], int path[], int pos, int V) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos, V)) {
            path[pos] = v;
            if (hamiltonianCircuitUtil(graph, path, pos + 1, V))
                return true;
            path[pos] = -1;
        }
    }

    return false;
}
void hamiltonianCircuit(bool graph[][MAX_VERTICES], int V) {
    int path[MAX_VERTICES];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0;
    if (!hamiltonianCircuitUtil(graph, path, 1, V)) {
        printf("Hamiltonian circuit does not exist\n");
        return;
    }
    printf("Hamiltonian circuit exists: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}
int main() {
    int V;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix (0/1) for the graph:\n");
    bool graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    hamiltonianCircuit(graph, V);
    return 0;
}
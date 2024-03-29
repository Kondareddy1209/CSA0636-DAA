#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10
int n, colors[MAX_VERTICES];
int adj_matrix[MAX_VERTICES][MAX_VERTICES];
bool is_safe(int v, int color) {
    for (int i = 0; i < n; i++) {
        if (adj_matrix[i][v] && colors[i] == color) {
            return false;
        }
    }
    return true;
}
bool graph_coloring_util(int v) {
    if (v >= n) {
        return true;
    }
    for (int color = 1; color <= n; color++) {
        if (is_safe(v, color)) {
            colors[v] = color;
            if (graph_coloring_util(v + 1)) {
                return true;
            }
            colors[v] = 0;
        }
    }
    return false;
}
bool graph_coloring() {
    for (int v = 0; v < n; v++) {
        colors[v] = 0;
    }
    if (!graph_coloring_util(0)) {
        printf("No valid coloring exists.\n");
        return false;
    }
    return true;
}
int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    if (graph_coloring()) {
        printf("Valid coloring exists with the following coloring:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d -> Color %d\n", i, colors[i]);
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20

bool isSafe(int vertex, int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int color[], int c) {
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int color[], int vertex, int maxColors) {
    if (vertex == vertices)
        return true;

    for (int c = 1; c <= maxColors; c++) {
        if (isSafe(vertex, graph, vertices, color, c)) {
            color[vertex] = c;

            if (graphColoringUtil(graph, vertices, color, vertex + 1, maxColors))
                return true;

            color[vertex] = 0; // Backtrack
        }
    }

    return false;
}

void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int maxColors) {
    int color[MAX_VERTICES] = {0};

    if (graphColoringUtil(graph, vertices, color, 0, maxColors)) {
        printf("Graph can be colored using %d colors as follows:\n", maxColors);
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d: Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("Graph cannot be colored using %d colors.\n", maxColors);
    }
}

int main() {
    int vertices, edges, maxColors;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = graph[v - 1][u - 1] = 1; // Mark edges
    }

    printf("Enter the maximum number of colors: ");
    scanf("%d", &maxColors);

    graphColoring(graph, vertices, maxColors);

    return 0;
}


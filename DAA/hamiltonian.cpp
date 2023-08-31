
3#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Graph representation using adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];
int vertices;

bool isSafe(int v, int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;
    
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    
    return true;
}

bool hamiltonianUtil(int path[], int pos) {
    if (pos == vertices) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    
    for (int v = 1; v < vertices; v++) {
        if (isSafe(v, path, pos)) {
            path[pos] = v;
            
            if (hamiltonianUtil(path, pos + 1))
                return true;
            
            path[pos] = -1; // Backtrack
        }
    }
    
    return false;
}

bool hamiltonianCircuit() {
    int path[MAX_VERTICES];
    for (int i = 0; i < vertices; i++)
        path[i] = -1;
    
    path[0] = 0; // Start from the first vertex
    
    if (!hamiltonianUtil(path, 1)) {
        printf("No Hamiltonian circuit exists.\n");
        return false;
    }
    
    printf("Hamiltonian circuit: ");
    for (int i = 0; i < vertices; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // Print the starting vertex to complete the circuit
    
    return true;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (hamiltonianCircuit()) {
        printf("Hamiltonian circuit exists.\n");
    }

    return 0;
}


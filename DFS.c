#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Maximum number of vertices in the graph

// Graph representation using adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

// Function to create a new graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    graph->visited = (bool*)malloc(numVertices * sizeof(bool));

    // Initialize adjacency lists and visited array
    for (int i = 0; i < numVertices; ++i) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to perform depth-first search (DFS) on the graph
void dfs(struct Graph* graph, int vertex) {
    // Mark the current vertex as visited
    graph->visited[vertex] = true;
    printf("%d ", vertex);

    // Recursively call dfs() for all adjacent vertices of the current vertex
    struct Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int adjVertex = adjList->data;
        if (!graph->visited[adjVertex]) {
            dfs(graph, adjVertex);
        }
        adjList = adjList->next;
    }
}

int main() {
    struct Graph* graph = createGraph(4); // Create a graph with 4 vertices

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printf("Depth-First Search (DFS) starting from vertex 0: ");
    dfs(graph, 0); // Start DFS from vertex 0

    return 0;
}

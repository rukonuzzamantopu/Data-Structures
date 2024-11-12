/*
#include <stdio.h>

#define MAX_VERTICES 100

void AddEdge (int graph[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void PrintGraph (int graph[MAX_VERTICES][MAX_VERTICES], int vtxs) {
    for (int i = 0; i < vtxs; i++) {
        for (int j = 0; j < vtxs; j++) {
            printf ("%d ", graph[i][j]); 
        }
        printf ("\n");
    }
}

int main () {
    int vertices = 6;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    AddEdge (graph, 0, 1);
    AddEdge (graph, 0, 3);
    AddEdge (graph, 0, 5);
    AddEdge (graph, 1, 2);
    AddEdge (graph, 2, 3);
    AddEdge (graph, 3, 4);
    AddEdge (graph, 4, 5);
    PrintGraph (graph, vertices);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int num_of_vertices;
    struct Node** adj_list;
};

struct Node* CreateNode (int vtx) {
    struct Node* nn = (struct Node*) malloc (sizeof (struct Node));
    nn->vertex = vtx;
    nn->next = NULL;
    return nn;
}

struct Graph* CreateGraph (int vtxs) {
    struct Graph* graph = (struct Graph*) malloc (sizeof (struct Graph));
    graph->num_of_vertices = vtxs;
    graph->adj_list = (struct Node**) malloc (vtxs * sizeof (struct Node*));
    
    for (int i = 0; i < vtxs; i++) 
        graph->adj_list[i] = NULL;
    
    return graph;
}

void AddEdge (struct Graph* graph, int src, int dst) {
    struct Node* nn = CreateNode (dst);
    nn->next = graph->adj_list[src];
    graph->adj_list[src] = nn;
    
    nn = CreateNode (src);
    nn->next = graph->adj_list[dst];
    graph->adj_list[dst] = nn;
}

void PrintGraph (struct Graph* graph) {
    for (int i = 0; i < graph->num_of_vertices; i++) {
        struct Node* temp = graph->adj_list[i];
        printf ("Vertex %d: ", i);
        while (temp) {
            printf ("->%d", temp->vertex);
            temp = temp->next;
        }
        printf ("\n");
    }
}

int main () {
    int vertices = 6;
    struct Graph* graph = CreateGraph (vertices);
    AddEdge (graph, 0, 1);
    AddEdge (graph, 0, 3);
    AddEdge (graph, 0, 5);
    AddEdge (graph, 1, 2);
    AddEdge (graph, 2, 3);
    AddEdge (graph, 3, 4);
    AddEdge (graph, 4, 5);
    PrintGraph (graph);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node {
    int data;
    struct s_node *next;
} t_node;

typedef struct s_graph {
    int numVertices;
    t_node **adjLists;
} t_graph;

t_node *createNode(int data) {
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

t_graph *createGraph(int numVertices) {
    t_graph *graph = malloc(sizeof(t_graph));
    if (!graph)
        return NULL;
    graph->numVertices = numVertices;
    graph->adjLists = malloc(numVertices * sizeof(t_node*));
    if (!graph->adjLists) {
        free(graph);
        return NULL;
    }
    for (int i = 0; i < numVertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(t_graph *graph, int src, int dest) {
    t_node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void freeGraph(t_graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        t_node *temp = graph->adjLists[i];
        while (temp) {
            t_node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjLists);
    free(graph);
}

void printGraph(t_graph *graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        t_node *temp = graph->adjLists[v];
        printf("\n Vertex %d\n: ", v);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int findMaxNode(char* input) {
    int maxNode = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        int src, dest;
        sscanf(token, "%d-%d", &src, &dest);
        if (src > maxNode) maxNode = src;
        if (dest > maxNode) maxNode = dest;
        token = strtok(NULL, " ");
    }
    return maxNode;
}

int main() {
    char input[] = "1-2 2-3 5-6 6-2 7-8 8-3 6-4 10-11 11-2 11-6";
    
    char tempInput[256];
    strncpy(tempInput, input, sizeof(tempInput));
    int maxNode = findMaxNode(tempInput);
    
    int numVertices = maxNode + 1;  // Adjust for 0-based indexing

    t_graph *graph = createGraph(numVertices);

    char* token = strtok(input, " ");
    while (token != NULL) {
        int src, dest;
        sscanf(token, "%d-%d", &src, &dest);
        addEdge(graph, src, dest);
        token = strtok(NULL, " ");
    }

    printGraph(graph);
    freeGraph(graph);

    return 0;
}

// Adjacency List (linked List)
// - hemat memori

#include <stdio.h>
#include <stdlib.h>

// Node yang merepresentasikan edge di adjacency list
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Structure graph
typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

// Membuat ndoe
Node* createNode(int dest){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Membuat Graph
Graph* createGraph(int numVertices){
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->numVertices = numVertices;

    // Membuat array dari adjacency list
    newGraph->adjList = (Node**)malloc(numVertices * sizeof(Node*));

    // Isi nilai setiap adjacency list dengan NULL
    for(int i = 0; i < numVertices; i++){
        newGraph->adjList[i] = NULL;
    }

    return newGraph;
}

// Menambahkan edge pada undericted graph (menghubungkan vertex secara undericted)
void addEdge(Graph* graph, int src, int dest){
    // Tambahkan edge dari vertex source ke vertex destination
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Tambahkan edge dari vertex destination ke vertex source
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Menampilkan graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        Node* temp = graph->adjList[i];
        printf("Adjacency list of vertex %d\n", i);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Membebaskan memori yang dipakai graph
void destroyGraph(Graph* graph){
    if(graph){
        if(graph->adjList){
            for(int i = 0; i < graph->numVertices; ++i){
                Node* temp = graph->adjList[i];
                while (temp){
                    Node* prev = temp;
                    temp = temp->next;
                    free(prev);
                }
            }
            free(graph->adjList);
        }
        free(graph);
    }
}

// Fungsi utama
int main(){
    Graph* graph = createGraph(5);
    
    // Menambahkan edge
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Menampilkan graph
    printGraph(graph);

    // Membebaskan memory dari graph
    destroyGraph(graph);
}
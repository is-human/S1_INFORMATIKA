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

// Membuat node
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
void printHimbauan(Graph* graph, int maxSimpang) {
    printf("Persimpangan yang harus dihindari oleh Roronoa Zoro adalah:\n");
    // Menghitung jumlah simpangan/cabang/jalan dari setiap persimpangan(vertex)
    int len = graph->numVertices;
    int intersectionBranchCount[len];
    for (int i = 0; i < len; ++i) {
        Node* temp = graph->adjList[i];
        intersectionBranchCount[i] = 0;
        while (temp) {
            intersectionBranchCount[i]++;
            temp = temp->next;
        }
        // Memeriksa dan menampilkan persimpangan yang tidak boleh dilewati Zoro
        if(intersectionBranchCount[i] > maxSimpang){
            printf("Persimpangan %d\n", i);
        }
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
void main(){
    int vertices, umurZoro, src, dest;
    // Menerima inputan jumlah persimpangan(vertex)
    printf("Jumlah Persimpangan(Vertex): ");
    scanf("%d", &vertices);
    // Membuat graph yang menampung vertices sejumlah yang diinputkan di atas
    Graph* graph = createGraph(vertices);
    // Menerima inputan jumlah minimum tetangga
    printf("Umur Roronoa Zoro(Batasan): ");
    scanf("%d", &umurZoro);
    // Menambahkan edge(jalan/cabang/simpangan)
    do{
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }while(src > -1 && dest > -1);

    // Menampilkan himbauan untuk Zoro sesuai umurnya
    printHimbauan(graph, umurZoro);

    // Membebaskan memory dari graph
    destroyGraph(graph);
}
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
void printWibu(Graph* graph, int minNeighbor) {
    // Menghitung jumlah tetangga dari tiap orang(vertex)
    int len = graph->numVertices;
    int neighborCount[len], nolep = -1;
    for (int i = 0; i < len; ++i) {
        Node* temp = graph->adjList[i];
        neighborCount[i] = 0;
        while (temp) {
            neighborCount[i]++;
            temp = temp->next;
        }
        // Menetapkan orang dengan tetangga paling sedikit (dibawah minimum)
        if(neighborCount[i] < minNeighbor){
            nolep = i;
        }
    }
    // Menyatakan vertex dari si wibu nolep
    if(nolep > -1){
        printf("Vertex %d adalah wibu nolep.", nolep);
    }else{
        printf("Tidak ditemukan wibu nolep dalam komplek perumahan(graph).");
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
    int vertices, minNeighbor, src, dest;
    // Menerima inputan jumlah orang(vertex)
    printf("Jumlah Orang(Vertex): ");
    scanf("%d", &vertices);
    // Membuat graph yang menampung vertices sejumlah yang diinputkan di atas
    Graph* graph = createGraph(vertices);
    // Menerima inputan jumlah minimum tetangga
    printf("Jumlah Minimum Tetangga: ");
    scanf("%d", &minNeighbor);
    // Menambahkan edge(hubungan tetangga)
    do{
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }while(src > -1 && dest > -1);

    // Menampilkan orang(vertex) dengan tetangga paling sedikit(di bawah minimum)
    printWibu(graph, minNeighbor);

    // Membebaskan memory dari graph
    destroyGraph(graph);
}
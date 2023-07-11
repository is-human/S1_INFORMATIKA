// Undericted Graph
// Adjacency Matrix
// - boros memori. sejumlah (jumlah vertex) pangkat 2 byte memori
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
    // jumlah vertex yang disimpan
    int numVertices;
    // menyimpan alamat graph
    int **adjMatrix;
}Graph;

// Fungsi untuk membuat graph baru dengan vertex awal
Graph *createGraph(){
    Graph *newGraph = malloc(sizeof(Graph));
    newGraph->numVertices = 0;
    newGraph->adjMatrix = NULL;
    return newGraph;
}

// Fungsi untuk menambahkan vertex baru ke dalam graph
void addVertex(Graph *graph){
    int newVertices = graph->numVertices + 1;

    // Alokasi memori untuk adjacency matrix baru
    // memperluas graph
    graph->adjMatrix = (int **)realloc(graph->adjMatrix, newVertices * sizeof(int *));
    // menyiapkan tempat/bar untuk data baru
    graph->adjMatrix[newVertices - 1] = (int *)malloc(newVertices * sizeof(int));

    for (int i = 0; i < newVertices; i++){
        graph->adjMatrix[i] = (int *)realloc(graph->adjMatrix[i], newVertices * sizeof(int));
        graph->adjMatrix[i][newVertices - 1] = 0;
        graph->adjMatrix[newVertices - 1][i] = 0;
    }

    graph->numVertices++;
}

// Fungsi untuk menambahkan sisi/edge antara dua simpul dalam graph
void addEdge(Graph *graph, int src, int dest){
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices && src != dest){
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;
    }else{
        printf("Invalid vertex!\n");
        system("pause");
    }
}

// Fungsi untuk mencetak adjacency matrix
void printGraph(Graph *graph){
    for (int i = 0; i < graph->numVertices; i++){
        for (int j = 0; j < graph->numVertices; j++){
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Fungsi utama
int main(){
    Graph *graph = createGraph();
    printGraph(graph);
    int pilihan;
    do{
        system("cls");
        printGraph(graph);
        printf("Menu\n1.Buat Vertex Baru\n2.Buat Edge\nMasukkan pilihan : ");
        scanf("%d", &pilihan);
        if (pilihan == 1){
            addVertex(graph);
        }
        else if (pilihan == 2){
            int src, dst;
            scanf("%d %d", &src, &dst);
            addEdge(graph, src, dst);
        }
    }while(pilihan != 0);
}

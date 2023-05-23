//header file yang dibutuhkan
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//menyiapkann Queue
#define MAX 50
typedef struct{
    char data[MAX];
    int front;
    int rear;
}Queue;
//prosedur untuk menginisialisasi queue dengan set nilai -1 ke front dan rear
void init(Queue *queue){
    queue->front = -1;
    queue->rear = -1;
}
//fungsi untuk memeriksa kosong tidaknya queue
bool isEmpty(Queue *queue){
    //memeriksa apakah front dan rear == -1, jika benar maka true (1)
    return (queue->front == -1 && queue->rear == -1) ? 1 : 0;
}
//fungsi untuk memeriksa penuh tidaknya queue
bool isFull(Queue *queue){
    // memeriksa apakah rear sudah senilai dengan nilai maximum - 1
    return (queue->rear == MAX - 1) ? 1 : 0;
}
//prosedur untuk menambahkan nilai ke antrian belakang Queue
void enqueue(Queue *queue, int value){
    //memastikan queue tidak penuh
    if(!isFull(queue)){
        //jika queue kosong, maka increment nilai front
        if(isEmpty(queue)) queue->front++;
        //increment nilai front sekaligus masukkan nilai
        queue->data[++queue->rear] = value;
        return;
    }
    //jika queue penuh tampilkan pesan berikut
    printf("Queue Penuh\n");
}
//menghapus nilai paling depan dalam queue
void dequeue(Queue *queue){
    //memastikan queue tidak kosong
    if(!isEmpty(queue)){
        //jika antrian tersisa 1 element, maka decrement nilai front
        if(queue->rear == queue->front)queue->front--;
        //memajukan element antrian ke depan
        for(int i = 0; i < queue->rear; i++){
            queue->data[i] = queue->data[i + 1];
        }
        //mengurangi jumlah antrian
        queue->rear--;
        return;
    }
    //jika queue penuh tampilkan pesan berikut
    printf("Queue Kosong\n");
}
//fungsi untuk mencari indeks karakter tunggal pertama dalam queue
int cariKarakterTunggalPertama(Queue *queue){
    //melakukan perulangan sepanjang queue untuk menyusur semua karakter
    for(int i = 0; i <= queue->rear; i++){
        //memeriksa kesamaan karakter2 dengan karakter indeks pertama
        for(int j = 1; j <= queue->rear; j++){
            //jika ada karakter yang sama, maka keluar
            if(queue->data[0] == queue->data[j]) break;
            //jika tidak ada kesamaan sampai akhir, maka kembalikan indeks
            if(j == queue->rear) return i;
        }
        //memindahkan element terdepan ke akhir antrian
        enqueue(queue, queue->data[0]);
        dequeue(queue);
    }
}
//fungsi utama yang pertama kali akan dijalankan program
void main(){
    //menyiapkan variabel yang diperlukan
    Queue str; char temp[MAX];
    init(&str);
    //menerima inputan berupa string
    scanf("%s", temp);
    //memasukkan karakter demi kareakter ke dalam Queue
    for(int i = 0; i < strlen(temp); i++){ enqueue(&str, temp[i]); }
    //menampilkan indeks yang dicari
    printf("%d", cariKarakterTunggalPertama(&str));
}
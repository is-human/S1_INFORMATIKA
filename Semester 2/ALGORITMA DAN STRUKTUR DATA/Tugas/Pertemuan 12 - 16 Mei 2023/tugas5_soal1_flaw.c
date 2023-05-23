//header file yang dibutuhkan
#include <stdio.h>
#include <stdbool.h>
//menyiapakan Queue
#define MAX 10
typedef struct{
    int data[MAX];
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
//prosedur untuk menghapus nilai paling depan dalam queue
void dequeue(Queue *queue){
    //memastikan queue tidak kosong
    if(!isEmpty(queue)){
        //jika antrian tersisa 1 element, maka decrement nilai front
        if(queue->rear == queue->front) queue->front--;
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
//prosedur untuk membagikan bubur ke mahasiwa sesuai selera
void bagiRata(Queue *mahasiswa, Queue *bubur){
    //variabel untuk menghitung ketidak cocokan selera
    int maxFail = -1;
    //melakukan perulangan selama antrian mahasiwa tidak kosong
    while(mahasiswa->rear >= 0){
        //jika antrian mahasiswa masih tidak cocok maka akhiri
        if(maxFail >= mahasiswa->rear) break;
        //jika mahasiswa dan buburnya cocok maka keluar antrian
        if(mahasiswa->data[0] == bubur->data[0]){
            //menghapus element tedepan masiswa dan bubur
            dequeue(mahasiswa);
            dequeue(bubur);
            maxFail = -1;
        }
        //jika belum cocok maka mahasiswa kembali ke belakang
        else{
            //memindahkan element tedepan ke akhir antrian mahasiswa
            enqueue(mahasiswa, mahasiswa->data[0]);
            dequeue(mahasiswa);
            maxFail++;
        }
    }
    //menampilkan jumlah mahasiswa yang tidak mendapat bubur yang cocok
    printf("Mahasiswa tidak cocok \t: %d", mahasiswa->rear + 1);
}
//fungsi utama yang akan dijalankan pertama oleh program
void main(){
    //menyiapkan variabel yang diperlukan
    Queue mahasiswa, bubur;
    init(&mahasiswa); init(&bubur);
    int len, temp;
    //menerima inputan jumlah antrian
    printf("Panjang antrian\t\t: ");
    scanf("%d", &len);
    printf("Antrian Mahasiswa\t: ");
    //menerima inputan antrian mahasiswa
    for(int i = 0; i < len; i++){
        scanf("%d", &temp);
        enqueue(&mahasiswa, temp);
    }
    //menerima inputan antrian bubur
    printf("Antrian Bubur\t\t: ");
    for(int i = 0; i < len; i++){
        scanf("%d", &temp);
        enqueue(&bubur, temp);
    }
    //membagikan bubur ke mahasiwa dalam antrian sesuai selera
    bagiRata(&mahasiswa, &bubur);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;
}Node;

Node *createNode(){
    Node *newNode = malloc(sizeof(Node));
    scanf(" %c", &(newNode->data));
    return newNode;
}

Node *insertNodes(Node *node, int len){
    Node *newNode[len];
    Node *tail = NULL;
    for(int i = 0; i < len; i++){        
        newNode[i] = createNode();
        if(node == NULL){
            node = newNode[0];
            tail = node;
        }else{
            tail->next = newNode[i];
            tail = tail->next;
        }
        if(i + 1 == len) tail->next = node;
    }
    return node;
}

int devourFromTail(Node *node, int len){
    Node *nearTail = NULL;
    int count = 0;
    for(int i = 0; i < len; i++){
        nearTail = node;
        while(nearTail->next->next != node){
            nearTail = nearTail->next;
        }
        if(nearTail->next->data == 'T'){
            Node *temp = nearTail->next;
            nearTail->next = node;
            count++;
            if(i + 1 == len) break;
        }else if(nearTail->next->data == 'B'){
            count++;
            break;
        }
    }
    return count;
}

int main(){
    Node *head = NULL;
    int len;
    printf("Panjang Ular : ");
    scanf("%d", &len);
    printf("Bagian Tubuh (kepala -> ekor) : ");
    head = insertNodes(head, len);
    printf("Ular mati ketika memakan ekornya sebanyak %d kali.", devourFromTail(head, len));
    return 0;
}
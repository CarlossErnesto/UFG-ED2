#include <stdio.h>
#include <stdlib.h>

//Struct do nó da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Struct da fila
typedef struct Queue {
    Node* front; 
    Node* rear;  
} Queue;

//Função para criar uma fila vazia
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue)); 
    q->front = q->rear = NULL;
    return q;
}

//Função para adicionar um elemento na fila
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = value;  
    newNode->next = NULL;   
    
    if (q->rear == NULL)    
        q->front = q->rear = newNode;
    else { 
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//Função para remover um elemento da frente da fila
int dequeue(Queue* q) {
    if (q->front == NULL) {  //Verifica se a fila está vazia
        printf("Fila está vazia.\n");
        return -1;  
    }
    Node* temp = q->front;   
    int data = temp->data;   
    q->front = q->front->next;  

    if (q->front == NULL)    
        q->rear = NULL;
    
    free(temp);  //Libera a memória do nó removido
    return data;  
}

//Função para imprimir os elementos da fila
void printQueue(Queue* q) {
    if (q->front == NULL)  { 
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;  
    printf("Elementos da fila: ");
    while (temp) { 
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int contarElementos(Queue* q) {
    int count = 0;  
    Node* temp = q->front;  
    while (temp) {  //Percorre todos os nós e conta
        count++;
        temp = temp->next;
    }
    return count;  
}

//Função para limpar e liberar memória
void limparFila(Queue* q) {
    while (q->front) {  
        dequeue(q);
    }
    printf("Todos os elementos da fila foram removidos.\n");
}

int main() {
    Queue* q = createQueue(); 
    enqueue(q, 10);  
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);  

    printf("Desenfileirado: %d\n", dequeue(q)); 
    printQueue(q);

    printf("Número de elementos na fila: %d\n", contarElementos(q));  

    limparFila(q);  
    printQueue(q);  //Tenta imprimir uma fila vazia

    free(q);
    return 0;
}

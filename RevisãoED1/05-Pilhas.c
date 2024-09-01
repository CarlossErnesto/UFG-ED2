#include <stdio.h>
#include <stdlib.h>
#define INITIAL_SIZE 3

//Struct da pilha
typedef struct {
    int* elementos; 
    int topo;       
    int capacidade; 
} Pilha;

//Função para criar uma pilha vazia com tamanho inicial definido
Pilha* criarPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha)); 
    p->elementos = (int*)malloc(INITIAL_SIZE * sizeof(int)); 
    p->topo = -1;         
    p->capacidade = INITIAL_SIZE; 
    return p;
}

//Verificão se a pilha está vazia
int estaVazia(Pilha* p) {
    return p->topo == -1; 
}

//Função para expandir a capacidade da pilha quando cheia
void expandirPilha(Pilha* p) {
    p->capacidade *= 2; 
    p->elementos = (int*)realloc(p->elementos, p->capacidade * sizeof(int));
    printf("Capacidade da pilha expandida para %d elementos.\n", p->capacidade); 
}

//Função para adicionar um elemento ao topo da pilha
void push(Pilha* p, int elemento) {
    if (p->topo == p->capacidade - 1) { 
        expandirPilha(p); 
    }
    p->elementos[++p->topo] = elemento; 
}

//Função para remover e retornar o elemento do topo da pilha
int pop(Pilha* p) {
    if (estaVazia(p)) { 
        printf("Pilha vazia!\n");
        return -1; 
    } 
    return p->elementos[p->topo--]; 
}

//Função para obter o elemento no topo da pilha sem removê-lo
int top(Pilha* p) {
    if (estaVazia(p)) { 
        printf("Pilha vazia!\n");
        return -1;
    } 
    return p->elementos[p->topo]; 
}


void imprimir(Pilha* p) {
    if (estaVazia(p)) { 
        printf("Pilha vazia!\n");
        return;
    }
    printf("Conteúdo da pilha:\n");
    for (int i = p->topo; i >= 0; i--) { 
        printf("%d ", p->elementos[i]);
    }
    printf("\n");
}


int main() {
    Pilha* p = criarPilha(); 
    push(p, 10);  
    push(p, 20);
    push(p, 30);
    imprimir(p);  

    printf("Elemento no topo: %d\n", top(p)); 
    printf("Elemento removido: %d\n", pop(p)); 
    imprimir(p); 

    //Limpeza de memória
    free(p->elementos); 
    free(p); 
    return 0;
}

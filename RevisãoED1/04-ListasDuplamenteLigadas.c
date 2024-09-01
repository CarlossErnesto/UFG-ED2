#include <stdio.h>
#define MAX_SIZE 10
int lista[MAX_SIZE];
int tamanho = 0;

//Não há interação por parte do usuário nesse código

//Função de inserir
void inserirElemento(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

//Função de remover
void removerElemento(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

//Função para buscar algum elemento
int buscar(int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == elemento) {
            return i; 
        }
    }
    return -1; 
}

void inverter() {
    int aux;
    for (int i = 0; i < tamanho / 2; i++) {
        aux = lista[i];
        lista[i] = lista[tamanho - i - 1];
        lista[tamanho - i - 1] = aux;
    }
}

int encontrarMaximo() {
    if (tamanho == 0) {
        return -1; 
    }
    int max = lista[0];
    for (int i = 1; i < tamanho; i++) {
        if (lista[i] > max) {
            max = lista[i];
        }
    }
    return max;
}

int encontrarMinimo() {
    if (tamanho == 0) {
        return -1; 
    }
    int min = lista[0];
    for (int i = 1; i < tamanho; i++) {
        if (lista[i] < min) {
            min = lista[i];
        }
    }
    return min;
}

//Função para ordenar os elementos
void ordenar() {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    inserirElemento(10);
    inserirElemento(20);
    inserirElemento(30);
    imprimir();
    removerElemento(1);
    imprimir();

    printf("Buscando o elemento 20: %d\n", buscar(20));
    inverter();
    imprimir();
    printf("Máximo: %d\n", encontrarMaximo());
    printf("Mínimo: %d\n", encontrarMinimo());
    ordenar();
    imprimir();

    return 0;
}

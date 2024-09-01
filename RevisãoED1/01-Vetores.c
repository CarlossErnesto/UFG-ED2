#include <stdio.h>

int main() {
    int n;  //armazena o tamanho do vetor

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];  //Declarando um vetor de tamanho n
    int i, temp;

    printf("Digite %d elementos do vetor:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < n / 2; i++) { 
        temp = vetor[i];  
        vetor[i] = vetor[n - 1 - i];  
        vetor[n - 1 - i] = temp;
    }

    // Imprime o vetor invertido
    printf("Vetor invertido:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);  
    }

    return 0;
}

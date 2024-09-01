#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz;
    int i, j, linhas, colunas, soma = 0;
    
    printf("Insira o tamanho desejado de linhas: ");
    scanf("%d", &linhas);
    printf("Insira o tamanho desejado de colunas: ");
    scanf("%d", &colunas);
    
    //Alocação dinâmica da matriz
    matriz = (int**) malloc(linhas * sizeof(int*));
    for (i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }
    
    printf("Insira os elementos da matriz %dx%d:\n", linhas, colunas);
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
            if (i == j) {  //Soma apenas os elementos da diagonal principal
                soma += matriz[i][j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    
    //Liberando a memória alocada
    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

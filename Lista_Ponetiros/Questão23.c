#include <stdio.h>
#include <stdlib.h>

// Função que soma os elementos correspondentes de vet1 e vet2 e armazena em resultado
void soma_vetores(int *vet1, int *vet2, int *resultado, int n) {
    for (int i = 0; i < n; i++) {
        resultado[i] = vet1[i] + vet2[i];
    }
}

int main() {
    int n;
    //tamanho dos vetores
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    // Alocação dinâmica dos vetores
    int *vet1 = (int *)malloc(n * sizeof(int));
    int *vet2 = (int *)malloc(n * sizeof(int));
    int *resultado = (int *)malloc(n * sizeof(int));

    // Leitura dos elementos do primeiro vetor
    printf("Digite os elementos do primeiro vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet1[i]);
    }

    // Leitura dos elementos do segundo vetor
    printf("Digite os elementos do segundo vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet2[i]);
    }
    soma_vetores(vet1, vet2, resultado, n);

    printf("Vetor resultado da soma:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(vet1);
    free(vet2);
    free(resultado);

    return 0;
}

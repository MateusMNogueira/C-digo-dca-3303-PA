#include <stdio.h>
// A: ponteiro para matriz A (dimensões: linhasA x colunasA)
// B: ponteiro para matriz B (dimensões: colunasA x colunasB)
// C: ponteiro para matriz C (dimensões: linhasA x colunasB) - resultado
// linhasA: número de linhas de A
// colunasA: número de colunas de A (igual ao número de linhas de B)
// colunasB: número de colunas de B
void multiplica_matrizes(const int *A, const int *B, int *C, int linhasA, int colunasA, int colunasB) {
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            C[i * colunasB + j] = 0;
            for (int k = 0; k < colunasA; k++) {
                C[i * colunasB + j] += A[i * colunasA + k] * B[k * colunasB + j];//i*colunasA + k] é o elemento da linha i e coluna k de A
                //k*colunasB + j] é o elemento da linha k e coluna j de B
                //i*colunasB + j] é o elemento da linha i e coluna j de C array em C é armazenado em uma única dimensão
            }
        }
    }
}
void imprime_matriz(const int *M, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%5d ", M[i * colunas + j]);
        }
        printf("\n");
    }
}

int main() {
    // Exemplo: A (2x3), B (3x4)
    int A[2 * 3] = {
        1, 2, 3,
        4, 5, 6
    };

    int B[3 * 4] = {
        7, 8, 9, 10,
        11, 12, 13, 14,
        15, 16, 17, 18
    };

    int C[2 * 4]; // Resultado 2x4

    multiplica_matrizes(A, B, C, 2, 3, 4);

    printf("Matriz A (2x3):\n");
    imprime_matriz(A, 2, 3);

    printf("\nMatriz B (3x4):\n");
    imprime_matriz(B, 3, 4);

    printf("\nMatriz C = A x B (2x4):\n");
    imprime_matriz(C, 2, 4);

    return 0;
}

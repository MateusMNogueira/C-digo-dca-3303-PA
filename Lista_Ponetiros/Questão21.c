#include <stdio.h>
#include <stdlib.h>  

void meu_sort(int *v, size_t n, int (*cmp)(int, int)) { //vetor, tamanho do vetor, ponteiro para funcao de comparacao
    for (size_t i = 0; i < n - 1; i++) { //compara cada elemento com todos os outros
        for (size_t j = i + 1; j < n; j++) {//compara o elemento i com todos os outros elementos
            if (cmp(v[i], v[j]) > 0) {//se a funcao de comparacao retornar > 0, troca os elementos
                int tmp = v[i];//tmp recebe o valor de v[i]
                v[i] = v[j];//v[i] recebe o valor de v[j]
                v[j] = tmp;//v[j] recebe o valor de tmp
            }
        }
    }
}

int campo_cres(int a, int b)  { return (a > b) - (a < b); }//retorna 1 se a > b, -1 se a < b, 0 se a == b
int campo_decre(int a, int b) { return (b > a) - (b < a); }//retorna 1 se b > a, -1 se b < a, 0 se a == b

int main(void) {
    int m;
    printf("quantidade de numero? ");
    scanf("%d", &m);

    int *v = malloc((size_t)m * sizeof *v);
    printf("Digite %d numeros:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &v[i]);
    }

    int opcao;
    printf("Escolha a ordem (1 = crescente, 2 = decrescente): ");
    scanf("%d", &opcao);
    if (opcao == 1){
        meu_sort(v, (size_t)m, campo_cres);
    }
    else{
        meu_sort(v, (size_t)m, campo_decre);
    }

    printf("Vetor ordenado:\n");
    for (int i = 0; i < m; i++) printf("%d ", v[i]);
    printf("\n");

    free(v);
    return 0;
}

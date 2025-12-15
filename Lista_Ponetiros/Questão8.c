#include <stdio.h>
int main(){
    int pulo[5] = {10, 20, 30, 40, 50}; // vetor de exemplo

    printf("Terceiro elemento do vetor: %d\n", *(pulo + 2));// O terceiro elemento do vetor fica na posiao 2
    printf("*(pulo + 4) = %d \n", *(pulo + 4));// O quinto elemento do vetor fica na posiao 4
    printf("pulo + 2 (endereco) = %p\n", (pulo + 2));//endereco do terceiro elemento do vetor
    printf("pulo + 4 (endereco) = %p\n", (pulo + 4));//endereco do quinto elemento do vetor
    return 0;
}

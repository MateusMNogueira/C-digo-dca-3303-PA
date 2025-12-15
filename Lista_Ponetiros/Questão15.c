#include <stdio.h>
int main(){
    unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6},
    {7, 8, 9}, {10, 11, 12}};
    printf("%u, %u, %u", x+3, *(x+3), *(x+2)+3);
    // x+3 é o endereço do 4º vetor (linha) do array x
    // *(x+3) é o endereço do 4º vetor (linha) do array x
    // *(x+2)+3 é o endereço do 4º elemento do 3º vetor (linha) do array x
    // Todos imprimem o mesmo endereço de memória
    return 0;
}

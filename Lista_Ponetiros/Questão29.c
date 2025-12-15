#include <stdio.h>
#include <stdlib.h>
// Para codificar os leds
unsigned long codificarleds(unsigned char matirz[8][8]){
    unsigned long estado;
    unsigned long *ponteiro;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            estado = estado << 1; // Desloca o estado para a esquerda
            estado = estado | matirz[i][j];// | matriz[i][j]; Operação OR bit a bit. Compara os bits de estado e matriz[i][j]
            // Se ambos os bits forem 1, o resultado é 1. Caso contrário, o resultado é 0.
        }
    }
    ponteiro = &estado;
    return estado;
}
int main(){
    unsigned char matriz[8][8] = {
        {1,0,0,0,0,0,0,1},
        {0,1,0,0,0,0,1,0},
        {0,0,1,0,0,1,0,0},
        {0,0,0,1,1,0,0,0},
        {0,0,0,1,1,0,0,0},
        {0,0,1,0,0,1,0,0},
        {0,1,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,1}
    };
    unsigned long estado = codificarleds(matriz);
    printf("Estado: ");
    for(int i=63;i>=0;i--){
        unsigned long bit = (estado >> i) & 1; 
        printf("%lu", bit);
    }
    printf("\n");
    return 0;
}

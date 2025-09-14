#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void funçao(char** str){
    *str = (*str) + 1;//altera o valor de str em main pois está alterando o conteúdo q está no ponteiro
    //str++;//não altera o valor de str em main
}

int main(){
    char *str = (void*) malloc(50 * sizeof(char));
    strcpy(str, "Agostinho");
    funçao(&str);
    puts(str);
    free(str);
    return 0;
}
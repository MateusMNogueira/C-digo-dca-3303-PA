#include <stdio.h>
void main(){
    int const *x = 3;
    printf("%d", ++(*x));
    //Código não compila, pois x é um ponteiro para um inteiro constante.
    return 0;
}
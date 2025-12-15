#include <stdio.h>
int main() {
    int mat[4] = {10,20,30,40};
    int *p,x;
    p = mat+1;//Operacao valida
    printf("%d\n", *p);
    p = mat++;//Operacao invalida pois mat e um vetor
    //printf("%d\n", *p);
    p = ++mat;//Operacao invalida pois mat e um vetor
    //printf("%d\n", *p);
    x = (*mat);//Operacao valida
    printf("%d\n", x);
    return 0;
}

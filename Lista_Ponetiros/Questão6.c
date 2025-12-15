#include <stdio.h>

void funcao(char **p){
char *t;
t = (p += sizeof(int))[-1];//t recebe o valor do ponteiro p deslocado 3 bytes para frente. Pois o p esta retocedendo 1 byte.
//Considerando o int com 4 bytes de tamanho
printf("%s\n", t);//gh 
}

int main(){
char *a[] = { "ab", "cd", "ef", "gh", "ij", "kl"};
//a[0] = ab
//a[1] = cd
//a[2] = ef
//a[3] = gh
//a[4] = ij
//a[5] = kl
funcao(a);
return 0;
}

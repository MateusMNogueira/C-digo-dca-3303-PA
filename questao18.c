/*Ponteiro para funçao eh uma variavel que armazena o endereço da funçao e permitindo chamar por meio da variavel*/

int soma(int a, int b){
    int s;
    s = a + b;
    return s;
}
int main(){
    int x,y;
    scanf("%d %d", &x, &y);
    int (*ponteiro)(int, int); //declaração do ponteiro para função
    ponteiro = soma; //atribuindo o endereço da função soma ao ponteiro
    int resultado = ponteiro(x, y); //chamando a função por meio do ponteiro
    printf("Resultado da soma: %d\n", resultado);
    return 0;
}

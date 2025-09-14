/*#include <stdio.h>
struct teste{
int x = 3;
char nome[5] = "jose";
};
//A inicialização de variaveis dentro de uma struct não é permitida.
int main(){
    struct teste *s;
    printf("%d", s->x);
    printf("%s", s->nome);
    return 0;
}
//Código não compila.*/
//Código corrigido:
#include <stdio.h>
#include <string.h>//biblioteca para usar a função strcpy
struct teste{
    int x;//declaração da variável x
    char nome[10];//declaração da variável nome
};

int main(){
    struct teste *s;//ponteiro para struct
    struct teste var;//variável do tipo struct
    var.x = 3;//Atribuição de valor para variavel x da struct var
    strcpy(var.nome, "jose");//Atribuição de valor para variavel nome da struct var
    s = &var;//ponteiro s recebe o endereço de var
    printf("x = %d", s->x);//imprime o valor de x apontada por s
    printf("\nnome = %s", s->nome);//imprime o valor de nome apontada por s
    return 0;
    //s->x e s->nome acessam os valores corretos da struct var através do ponteiro s.
}



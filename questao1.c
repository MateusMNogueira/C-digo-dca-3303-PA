int main(){
    int i=3, j=5;
    int *p,*q;
    p = &i;
    q = &j;
    //if(p==&i){
    //    printf("true"); //Isso acontence porque p aponta para o endereco de i que vale 3
    //}

    //int valor = *p - *q; //valor = 3 - 5
    //printf("Valor: %d\n", valor);
    
    //int valor2 = **&p; // O &p pega o endereco de p, e o * antes dele referencia esse endereco pegando o valor que esta em p, que eh o endereco de i. O segundo * se refere ao endereço de i pegando o seu valor de 3.
    //printf("Valor2: %d\n", valor2);

    //int equacao = 3 - *p/(*q) + 7; //3 - 3/5 + 7 = 10. A divisao como são dois inteiros, o resultado eh 0.
    //printf("Equacao: %d\n", equacao);
    return 0; 
}
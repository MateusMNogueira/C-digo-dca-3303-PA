int main(){
    int i,j;
    int *p,*q;
    p = &i;//Valido, p aponta para i
    *q = &j;//Invalido, *q é int (lvalue), &j é int* — tipos incompatíveis.
    p = &*&i;//Valido, pq o &i pega o endereco de i e o * antes dele referencia esse endereco pegando o valor que esta em i, ou seja, p aponta para i
    i = (*&)j;//Invalido, pq *& nao é uma expressão válida
    i = *&j;//Valido, pq o &j pega o endereco de j e o * antes dele referencia esse endereco pegando o valor que esta em j, ou seja, i recebe o valor de j
    i = *&*&j;//Valido, (operações & e * se cancelam apropriadamente).
    q = *p;//Invalido, *p é int, q é int*: tipos incompatíveis.
    i = (*p)++ + *q;//Valido, (*p)++ é o valor de i antes do incremento, *q é o valor de j.
    return 0;
}
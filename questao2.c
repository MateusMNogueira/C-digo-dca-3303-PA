int main(){
    int i=5, *p;
    p = &i;
    printf("%p %p %d %d %d %d\n", p, p+1, *p+2, **&p, 3**p, **&p+4);
    //0000005A6C9FF8CC 0000005A6C9FF8D0 7 5 15 9
    //Explicacao: Os dois primeiros são valores de memoria, a memória de i e a memória de 4 bytes a mais.
    //Continuação: O terceiro é o valor de i + 2, o quarto é o valor de i, o quinto é 3 vezes o valor de i e o sexto é o valor de i + 4.
} 

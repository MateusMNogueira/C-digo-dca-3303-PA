#include <stdio.h>
    char *a[] = {"AGOSTINHO", "MEDEIROS", "BRITO", "JUNIOR"};
    char **b[] = {a + 3, a + 2, a + 1, a};
    char ***c = b;
    int main() {
    printf("%s ", **++c);// Brito. Pois c aponta para b[1], que aponta para a[2].
    printf("%s ", *--*++c + 3);// Stinho. ++c move para b[2], *++c acessa o conteudo de b[2] q eh a+1, --*++c move para a[0], +3 move 3 posicoes no string "AGOSTINHO" 
    printf("%s ", *c[-2] + 3);// Ior. c atual b[2], c[-2] move 2 posicoes para b[0], que aponta para a+3, *c[-2] acessa a[3] "JUNIOR", +3 move 3 posicoes no string "JUNIOR"
    printf("%s ", c[-1][-1] + 1);// Edeiros. c[-1] = b[1], c[-1][-1] = a[1] "MEDEIROS", +1 move 1 posicao no string "MEDEIROS"
    return 0;
}

/*
#1 - Compila o programa: "gcc -S -c -O3 codigo.c", tendo em vista que "-c" 
obriga não fazer o linker (por exemplo não colocando o printf no arquivo gerado,
somente um jump) e o principal o "-S" que faz com que o arquivo de saída do 
compilador seja um arquivo com as instruções em assembly. Isso somado com "-O3" 
que é otimização máxima do gcc.

#2 - Usando "__asm()" você colocar dentro dele o código otimizado "-O3" que foi 
gerado. Após isso o indivíduo manda para o SPOJ. Isso implica que mesmo se o 
SPOJ não otimize, o código fique naturalmente muito otimizado porque o 
compilador já fez uma vez.
*/

#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == EOF) return (EOF);
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

int main() {
    int n;
    while (n = get_int()) {
        if (n < 101) printf("f91(%d) = 91\n", n);
        else printf("f91(%d) = %d\n", n, n-10);
    }
    return 0;
}

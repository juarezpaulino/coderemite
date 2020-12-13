/*
#1 - Compila o programa: "gcc -S -c -O3 codigo.c", tendo em vista que "-c" 
obriga n�o fazer o linker (por exemplo n�o colocando o printf no arquivo gerado,
somente um jump) e o principal o "-S" que faz com que o arquivo de sa�da do 
compilador seja um arquivo com as instru��es em assembly. Isso somado com "-O3" 
que � otimiza��o m�xima do gcc.

#2 - Usando "__asm()" voc� colocar dentro dele o c�digo otimizado "-O3" que foi 
gerado. Ap�s isso o indiv�duo manda para o SPOJ. Isso implica que mesmo se o 
SPOJ n�o otimize, o c�digo fique naturalmente muito otimizado porque o 
compilador j� fez uma vez.
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

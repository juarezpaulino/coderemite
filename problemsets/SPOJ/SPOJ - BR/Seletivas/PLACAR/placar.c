#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nota;
    char nome[21];
} aluno;

aluno x[100], m;
char *str;
int n, menor;

int main() {
    
    int i, c = 1;
    
    while (scanf("%d ", &n) != EOF) {
        for (i = 0; i < n; i++)
            scanf("%s %d ", x[i].nome, &x[i].nota);
        
        menor = x[0].nota; str = x[0].nome;
        for (i = 1; i < n; i++) {
            if (x[i].nota < menor) { str = x[i].nome; menor = x[i].nota; }
            else if ((x[i].nota == menor) && (strcmp(x[i].nome, str) > 0)) str = x[i].nome;
        }
        
        printf("Instancia %d\n", c++);
        printf("%s\n\n", str);
    }
    
    return 0;
}

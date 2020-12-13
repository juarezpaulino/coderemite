#include <stdio.h>
#include <string.h>

char mem[30010];
char in[100005];
char exec[100005];
int p, pin, szin;
int ind[100005], top;

int main() {

    int n, c;
    int l;
    int i, j;
    
    scanf("%d ", &n);
    for (c = 1; c <= n; c++) {
        printf("Instancia %d\n", c);
        gets(in); gets(exec);
        memset(mem, 0, sizeof(mem)); p = 0; pin = 0; szin = strlen(in)-1; top = -1;
        for (i = 0; exec[i] != '\0'; i++) {
            switch (exec[i]) {
                case '>': p++; break;
                case '<': p--; break;
                case '+': mem[p]++; break;
                case '-': mem[p]--; break;
                case '.': putchar(mem[p]); break;
                case ',': mem[p] = (pin > szin) ? 0 : in[pin++]; break;
                case '#': for (j = 0; j < 10; j++) putchar(mem[j]); break;
                case '[':
                    if (!mem[p]) {
                        for (l = 1; l; )
                            if (exec[++i] == '[') l++; else if (exec[i] == ']') l--;
                    }
                    else ind[++top] = i-1;
                    break;
                case ']':
                    i = ind[top--];
                    break;
                default: ;
            }
        }
        printf("\n\n");
        gets(in);
    }   
    
    return 0;
}

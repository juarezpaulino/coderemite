#include <stdio.h>


int c, n;
char pre[55], em[55];
char pos[128], esq[128], dir[128];
char ocupado[55];
int no;

void percorrer(char pai, char left) {
    char ch = pre[no];
    int p = pos[ch];
    ocupado[p] = 1;
    if (p>0 && !ocupado[p-1]) { no++; percorrer(ch, 1); }
    if (p<n-1 && !ocupado[p+1]) { no++; percorrer(ch, 0); }
    if (pai != -1) {
        if (left) esq[pai] = ch;
        else dir[pai] = ch;
    }
}

void posord(char ch) {
    if (esq[ch] != -1) posord(esq[ch]);
    if (dir[ch] != -1) posord(dir[ch]);
    putchar(ch);
}


int main() {
    
    int i;
    
    scanf("%d ", &c);
    while (c--) {
        scanf("%d %s %s ", &n, pre, em);
        for (i = 0; i < n; i++) ocupado[i] = 0;
        for (i = 0; em[i]; i++) { pos[em[i]] = i; esq[em[i]] = dir[em[i]] = -1; }
        no = 0; percorrer(-1, 0);
        posord(pre[0]); putchar('\n');
    }
    return 0;
}

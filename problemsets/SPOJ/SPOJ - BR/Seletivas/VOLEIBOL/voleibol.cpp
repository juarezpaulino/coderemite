/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <string>


#define _inline(f...) f() __attribute__((always_inline)); f

using namespace std;

struct times {
    char nome[25];
    int win, sets, pg;
};

int t, m;
map<string,int> mapa;
times clube[1000];

int cmp(const void *a, const void *b) {
    times *x = (times*)a, *y = (times*)b;
    if (x->win != y->win) return y->win-x->win;
    else if (x->sets != y->sets) return y->sets-x->sets;
    else if (x->pg != y->pg) return y->pg-x->pg;
    return strcmp(x->nome, y->nome);
}


int main() {

    int i, j, x, y, w, l, p1, p2;
    char str[25], jogo[500];

    while (scanf("%d ", &t)) {
        if (!t) break; mapa.clear();
        for (i = 0; i < t; i++) { 
            gets(str); mapa[str]=i; strcpy(clube[i].nome,str);
            clube[i].win = clube[i].sets = clube[i].pg = 0;
        }
        scanf("%d ", &m);
        while (m--) {
            gets(jogo); i = j = 0;
            while (jogo[i]!='-') str[j++] = jogo[i++]; str[j] = 0; x = mapa[str];
            i++; j = 0;
            while (jogo[i]!=':') str[j++] = jogo[i++]; str[j] = 0; y = mapa[str];
            i++; w = l = 0;
            while (jogo[i]) {
                while (jogo[i]==' ') i++; if (!jogo[i]) break;
                for (p1 = 0; jogo[i]>='0' && jogo[i]<='9'; i++) p1 = p1*10+jogo[i]-'0';
                for (p2 = 0, i++; jogo[i]>='0' && jogo[i]<='9'; i++) p2 = p2*10+jogo[i]-'0';
                clube[x].pg += p1; clube[y].pg += p2; if (p1 > p2) w++; else l++;
            }
            clube[x].sets += w-l; clube[y].sets += l-w;
            if (w > l) clube[x].win++; else clube[y].win++;
        }
        qsort(clube, t, sizeof(times), cmp);
        for (i = 0; i < t; i++)
            printf("%-20s %4d %4d %9d\n", clube[i].nome, clube[i].win, \
                                          clube[i].sets, clube[i].pg);
        putchar('\n');
    }
    
    return 0;
}

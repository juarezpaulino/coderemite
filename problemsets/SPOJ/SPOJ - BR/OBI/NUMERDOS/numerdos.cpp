/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <map>
#include <string>
#include <list>
#include <string.h>
#include <iostream>

#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define INF 0x3F3F3F3F

using namespace std;


map<pair<string, char>, int> autor; int na;
int num[100];
list<int> data[100];
char valid[100], sobre[100][50];


int main() {
    
    int n; register int i, j, k, x, m, c, teste = 1;
    char str[500], nome[40], p;
    while (scanf("%d ", &n) && n) {
        autor.clear();
        for (i = na = 0; i < n; i++) {
            gets(str); data[i].clear(); valid[i] = 1;
            p = str[0];
            for (j = 3, k = 0; str[j]; j++)
                if (str[j] == ',') { 
                    nome[k] = 0;
                    if (!autor.count(make_pair(nome, p))) {
                        x = autor[make_pair(nome, p)] = na++;
                        strcpy(sobre[x], nome); num[x] = INF;
                    }
                    else x = autor[make_pair(nome, p)];
                    data[i].push_back(x);
                    p = str[j+2]; k = 0; j+=4;
                }
                else nome[k++] = str[j];
            nome[k-1] = 0;
            if (!autor.count(make_pair(nome, p))) {
                x = autor[make_pair(nome, p)] = na++;
                strcpy(sobre[x], nome); num[x] = INF;
            }
            else x = autor[make_pair(nome, p)];
            data[i].push_back(x);
        }
        if (autor.count(make_pair("Erdos", 'P'))) num[autor[make_pair("Erdos", 'P')]] = 0;
        for (m = 0, c = 1; c; m++) {
            c = 0;
            for (i = 0; i < n; i++) if (valid[i]) foreach(it, all(data[i])) if (m == num[*it]) {
                foreach(it1, all(data[i])) {
                    if (num[*it1] > m+1) { num[*it1] = m+1; c = 1; }
                }
                valid[i] = 0; break;
            }
        }
        printf("Teste %d\n", teste++);
        foreach(it, all(autor)) if ((it->first.first != "Erdos") || (it->first.second != 'P')) {
            printf("%c. %s: ", it->first.second, sobre[it->second]);
            if (num[it->second] == INF) puts("infinito");
            else printf("%d\n", num[it->second]);
        }
        putchar('\n');
    }
    
    return 0;
}


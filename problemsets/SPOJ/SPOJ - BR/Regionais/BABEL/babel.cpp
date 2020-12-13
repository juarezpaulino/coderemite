/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <string>

#define MAXV 2020


#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()

using namespace std;

const int INF = 0x7FFFFFFF;

typedef struct {
    char head;
    int len;
    int pos;
} word;


int m, nd;

map<string, int> lang;
vector<list<word> > dic;
char ori[100], des[100];

int adj[MAXV][MAXV], custo[MAXV][MAXV];
int nadj[MAXV], marc[MAXV], dist[MAXV];


void dijkstra(int ini) {
    int i, k, a;
    int d;
    
    priority_queue<pair<int, int> > heap;
    memset(marc, 0, sizeof(marc));

    for (i = 0; i < m+2; i++) dist[i] = INF;
    heap.push(make_pair(dist[ini] = 0, ini));
    
    while (!heap.empty()) {
        i = heap.top().second; heap.pop();
        if (i == 1) break;
        if (marc[i]) continue; marc[i] = 1;
        for (k = 0; k < nadj[i]; k++) {
            a = adj[i][k]; d = dist[i] + custo[i][k];
            if (d < dist[a]) heap.push(make_pair( -(dist[a] = d), a));
        }
    }
}


int main() {
    
    char s[100], d[100], w[100];
    word node;
    int i;
    
    while (scanf("%d ", &m)) {
        
        if (!m) break;
        
        lang.clear();
        nd = 2;     // Nodos 0 e 1 sao inicio e fim.
        scanf("%s %s ", ori, des);
        lang[ori] = nd++; lang[des] = nd++;
        
        nadj[0] = nadj[1] = 0;
        dic.clear(); dic.resize((m<<1)+10);     // Redimensiona tam do dicionario de linguas.
        for (i = 2; i < m+2; i++) {
            scanf("%s %s %s ", s, d, w);
            nadj[i] = 0;
            
            if (!lang[s]) lang[s] = nd++;
            if (!lang[d]) lang[d] = nd++;
            
            /* Monta o nodo. */
            node.head = *w; node.len = strlen(w); node.pos = i;
            dic[lang[s]].push_back(node);
            dic[lang[d]].push_back(node);
            
            /* Trata se os idiomas sao de destino ou origem. */
            if ((lang[s] == lang[des]) || (lang[d] == lang[des])) dic[1].push_back(node);
            if (lang[s] == lang[ori]){
                node.len = 0; dic[0].push_back(node);
            }
            if (lang[d] == lang[ori]){
                node.len = 0; dic[0].push_back(node);
            }
        }
        
        /* Constroi o grafo de palavras. */
        foreach(it, all(dic[0])) {
            adj[0][nadj[0]] = it->pos; custo[0][nadj[0]++] = 0;
        }
        foreach(it, all(dic[1])) {
            adj[it->pos][nadj[it->pos]] = 1; custo[it->pos][nadj[it->pos]++] = it->len;
        }
        for (i = 2; i < nd; i++) {
            foreach(it, all(dic[i])) {
                foreach(it2, it, dic[i].end()) {
                    if ((it == it2) || (it->head == it2->head)) continue;
                    adj[it->pos][nadj[it->pos]] = it2->pos; 
                    custo[it->pos][nadj[it->pos]++] = it->len;
                    adj[it2->pos][nadj[it2->pos]] = it->pos;
                    custo[it2->pos][nadj[it2->pos]++] = it2->len;
                }
            }
        }
        
        
        dijkstra(0);
        
        if (dist[1] == INF) printf("impossivel\n");
        else printf("%d\n", dist[1]);
    }
    
    return 0;
}

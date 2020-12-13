/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <queue>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define BE(a) ((a).begin()),((a).end())
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define TLE while(1);
#define RTE printf("%d", 1/0);


using namespace std;

int adj[2][10000][2], nadj[2][10000];
map<int, int> node;
char val[2][10000][130];
map<string, int> out;
int fim;

void dfs(int a, int v, int ret) {
    int i, j, k;
    if (fim) return;
    if (nadj[a][v]==0) {
        if (!a) out[val[a][v]] = adj[a][v][0];
        else if (adj[a][v][0]!=ret) { fim = 1; return; }
    }
    else if (nadj[a][v]==1) {
        i = adj[a][v][0]; strcpy(val[a][i], val[a][v]); dfs(a, i, ret);
    }
    else if (nadj[a][v]==2) {
        i = adj[a][v][0]; strcpy(val[a][i], val[a][v]);
        k = strlen(val[a][v]); val[a][i][k++] = '0'; val[a][i][k] = 0;
        j = ret; if (a && ret==-1 && out.count(val[a][i])) j = out[val[a][i]];
        dfs(a, i, j);
        i = adj[a][v][1]; strcpy(val[a][i], val[a][v]);
        k = strlen(val[a][v]); val[a][i][k++] = '1'; val[a][i][k] = 0;
        j = ret; if (a && ret==-1 && out.count(val[a][i])) j = out[val[a][i]];
        dfs(a, i, j);
    }
    else TLE;
}


int main() {

    int i, t, p, l1, l2, k, c;
    char str[100], op[20];
    for (scanf("%d", &t); t--; ) { for (scanf("%d", &p); p--; ) {
        CLR(nadj, 0), out.clear();
        
        scanf("%*d ");
        // Arvore 1
        node.clear(); k = 0; c = -1;
        while (gets(str) && strcmp(str, "END")) {
            if (sscanf(str, "%d %s %d", &l1, op, &l2)==3) {
                (node.count(l1))?(l1=node[l1]):l1=node[l1]=k++;
                (node.count(l2))?(l2=node[l2]):l2=node[l2]=k++;
            }
            else (node.count(l1))?(l1=node[l1]):l1=node[l1]=k++;
            c = (c!=-1)?adj[0][c][0]=l1,-1:-1;
            if (!strcmp(op,"BRTRUE")) nadj[0][l1] = 2, c = l1, adj[0][l1][1] = l2;
            else if (!strcmp(op,"JMP")) adj[0][l1][nadj[0][l1]++] = l2;
            // Nao existe adjacencia nas folhas, adj[][] usado como marcador
            // do valor
            else if (!strcmp(op,"RET0")) adj[0][l1][0] = '0';
            else if (!strcmp(op,"RET1")) adj[0][l1][0] = '1';
            else TLE;
        }
        if (c!=-1) TLE;
        
        // Arvore 2
        node.clear(); k = 0; c = -1;
        while (gets(str) && strcmp(str, "END")) {
            if (sscanf(str, "%d %s %d", &l1, op, &l2)==3) {
                (node.count(l1))?(l1=node[l1]):l1=node[l1]=k++;
                (node.count(l2))?(l2=node[l2]):l2=node[l2]=k++;
            }
            else (node.count(l1))?(l1=node[l1]):l1=node[l1]=k++;
            c = (c!=-1)?adj[1][c][0]=l1,-1:-1;
            if (!strcmp(op,"BRTRUE")) nadj[1][l1] = 2, c = l1, adj[1][l1][1] = l2;
            else if (!strcmp(op,"JMP")) adj[1][l1][nadj[1][l1]++] = l2;
            // Nao existe adjacencia nas folhas, adj[][] usado como marcador
            // do valor
            else if (!strcmp(op,"RET0")) adj[1][l1][0] = '0';
            else if (!strcmp(op,"RET1")) adj[1][l1][0] = '1';
            else TLE;
        }
        if (c!=-1) TLE;
        
        // Percorre as duas arvores e compara se deixam a mesma saida.
        val[0][0][0] = val[1][0][0] = 0; fim = 0;
        dfs(0, 0, -1); dfs(1, 0, -1);
        if (fim) printf("0\n"); else printf("1\n");
        
    } if (t) putchar('\n'); }
    
    return 0;
}

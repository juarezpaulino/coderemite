/* Zak Galou */

#include <stdio.h>

#define INF 1500000000

int m, n, g, k;
char gal[1001][1001];
int mana[1001], dano[1001];
int dist[1001];
int sal[1001];
int dp[1001];
char disc[1001];

void dijkstra(int s) {
    
    int i;
    int v;
    int w;
    int d;
    
    dist[s] = sal[s];
    v = s;
    
    while (!disc[v]) {
        if (v == n) break;
        disc[v] = 1;
        for (i = 1; i <= n; i++) {
            if ((i != v) && (gal[v][i]))
                if (dist[i] > dist[v]+sal[i])
                    dist[i] = dist[v]+sal[i];
        }
        
        d = INF;
        v = 1;
        for (i = 1; i <= n; i++)
            if ((!disc[i]) && (d > dist[i])) {
                d = dist[i];
                v = i;
            }
    }
}


int main() {
        
    int i, j;
    int a, b;
    char flag;
    int max;
    
    while (scanf("%d %d %d %d", &m, &n, &g, &k)) {
    
        if ((!m) && (!n) &&(!g) && (!k)) break;
        
        for (i = 1; i <= m; i++) scanf("%d %d", &mana[i], &dano[i]);
        
        /* Calcula Mana pra cada dano - DP */
        dp[0] = 0;
        for (i = 1; i <= 1000; i++) {
            dp[i] = INF;
            for (j = 1; j <= m; j++)
                if ((i-dano[j]) < 0) {
                    if (mana[j] < dp[i]) 
                        dp[i] = mana[j];
                }
                else {
                    if (dp[i-dano[j]]+mana[j] < dp[i])
                        dp[i] = dp[i-dano[j]]+mana[j];
                }
        }
        
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) gal[i][j] = 0;
            dist[i] = INF;
            disc[i] = 0;
            sal[i] = 0;
        }
        
        for (i = 0; i < g; i++) {
            scanf("%d %d", &a, &b);
            gal[a][b] = gal[b][a] = 1;
        }
        
        for (i = 0; i < k; i++) {
            scanf("%d %d", &a, &b);
            sal[a] = sal[a]+dp[b];   
        }
        
        dijkstra(1);
        
        if (dist[n] == INF) printf("-1\n");
        else printf("%d\n", dist[n]);
    }
    
    return 0;
}

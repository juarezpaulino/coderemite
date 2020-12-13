/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
int height[510];
char music[510][50], sport[510][50];
int disc[510];
int par[510];
int adj[510][510], nadj[510];
int match;
int comp;

int augment(int v) {
    int i;
    for (i = 0; i < nadj[v]; i++) if (disc[adj[v][i]] != comp) {
        disc[adj[v][i]] = comp;
        if (!par[adj[v][i]] || augment(par[adj[v][i]])) {
            par[adj[v][i]] = v; par[v] = adj[v][i]; return 1;
        }
    }
    return 0;
}


int main() {

    int t, x, v;
    char str[10];
    int i, j, k;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n); j = 1; k = n;
        for (i = 1; i <= n; i++) {
            scanf("%d %s ", &x, str); v = (*str=='F') ? j++ : k--;
            scanf("%s %s ", music[v], sport[v]); height[v] = x;
        }
        m = j; match = 0;
        for (i = 0; i <= n; i++) nadj[i] = disc[i] = par[i] = 0;
        for (i = 1; i < m; i++)
            for (j = m; j <= n; j++)
                if (abs(height[i]-height[j])<=40 && !strcmp(music[i], music[j]) && strcmp(sport[i], sport[j])) {
                    adj[i][nadj[i]++] = j;
	                if (!par[i] && !par[j]) par[j] = i, par[i] = j, match++;
	            }
	    for (i = comp = 1; i < m; i++, comp++) if (!par[i]) match += augment(i);
	    printf("%d\n", n-match);
    }

    return 0;
}

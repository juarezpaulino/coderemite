/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

int adj[6][6] = {
 {},
 { 0, 0, 1, 1, 0, 1 },
 { 0, 1, 0, 1, 0, 1 },
 { 0, 1, 1, 0, 1, 1 },
 { 0, 0, 0, 1, 0, 1 },
 { 0, 1, 1, 1, 1, 0 },
                };

int V[6][6];
char S[10];

void go(int k, int p) {
    S[k] = p+'0';
    if (k == 8) { S[k+1] = 0; puts(S); return; }
    for (int i = 0; i < 6; i++) if (adj[p][i]) {
        adj[p][i] = adj[i][p] = 0;
        go(k+1, i);
        adj[p][i] = adj[i][p] = 1;
    }
}

int main() {

    go(0, 1);

    return 0;
}

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
#include <set>
#include <queue>

using namespace std;

char PR[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};

vector<int> ADJ[20];
int N;

int RET[20], USE[20];

void go(int k, int p) {
    if (k == N) {
        if (PR[p+1]) {
            printf("%d", RET[0]);
            for (int i = 1; i < N; i++) printf(" %d", RET[i]);
            putchar('\n');
        }
        return;
    }
    for (int i = 0; i < ADJ[p].size(); i++) if (!USE[ADJ[p][i]]) {
        USE[ADJ[p][i]] = 1;
        RET[k] = ADJ[p][i];
        go(k+1, ADJ[p][i]);
        USE[ADJ[p][i]] = 0;
    }
}

int main() {

    int T = 1;
    bool f = false;
    while (scanf("%d", &N) != EOF) {
        if (f) putchar('\n');
        f = 1;
        printf("Case %d:\n", T++);
        if (N == 1) { putchar('\n'); continue; }
        for (int i = 1; i <= N; i++) for (int j = i+1; j <= N; j++) if (PR[i+j])
            ADJ[i].push_back(j), ADJ[j].push_back(i);
        RET[0] = USE[1] = 1;
        go(1, 1);
        for (int i = 1; i <= N; i++) ADJ[i].clear();
    }

    return 0;
}

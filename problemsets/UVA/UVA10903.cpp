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
#include <numeric>

using namespace std;

map<string,int> M;

int W[110], L[110];
int N, K;

int main() {

    M["rock"] = 0;
    M["scissors"] = 1;
    M["paper"] = 2;
    bool f = false;
    while (scanf("%d %d", &N, &K)) {
        if (!N) break;
        if (f) putchar('\n');
        f = 1;
        for (int i = 1; i <= N; i++) W[i] = L[i] = 0;
        for (int i = 0; i < N*(N-1)/2 * K; i++) {
            int p1, p2, m1, m2;
            char S1[30], S2[30];
            scanf("%d %s %d %s", &p1, S1, &p2, S2);
            m1 = M[S1]; m2 = M[S2];
            if (m1 == m2) continue;
            if ((m1+4)%3 == m2) W[p1]++, L[p2]++;
            else W[p2]++, L[p1]++;
        }
        for (int i = 1; i <= N; i++) {
            if (!(W[i]|L[i])) puts("-");
            else printf("%.3lf\n", W[i] / (double)(W[i]+L[i]));
        }
    }

    return 0;
}

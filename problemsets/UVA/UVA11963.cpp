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

struct activity { char ind; long long F, V; };

int T, K, N;
long long M;
bool USED[20];
activity C[20];
vector<int> A[20];
vector<long long> P[20];
int POS[20];
long long ret;



long long compute() {
    long long c = M, ret = 0;
    for (int i = 0; i < K; i++) if (POS[i]!=-1) {
        c -= C[i].F;
    }
    int k = 0;
    while (k < K) {
        if (POS[k]==-1) { k++; continue; }
        int u = POS[k];
        int i;
        for (i = 0; i < (int)A[u].size(); i++) if (A[u][i]==k) break;
        if (c - C[k].V*P[u][i] >= 0) ret += P[u][i], c += C[k].V*P[u][i];
        else {
            ret += c / C[k].V;
            c -= (c / C[k].V) * C[k].V;
        }
        k++;
    }
    return ret;
}

void go(int k) {
    if (k == K) {
        ret = max(ret, compute());
        return;
    }
    for (int i = 0; i < N; i++) if (!USED[i]) {
        int j;
        for (j = 0; j < (int)A[i].size(); j++) if (A[i][j]==k) break;
        if (j == (int)A[i].size()) continue;
        POS[k] = i;
        USED[i] = 1;
        go(k+1);
        USED[i] = 0;
        POS[k] = -1;
    }
    go(k+1);
}

bool comp(const activity &A, const activity &B) {
    if (A.V != B.V) return A.V < B.V;
    return A.F < B.F;
}

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %lld", &K, &N, &M);
        M *= 1000000LL;
        for (int i = 0; i < K; i++) {
            char ch;
            scanf(" %c %lld %lld", &ch, &C[i].F, &C[i].V);
            C[i].F *= 1000LL;
            C[i].ind = ch;
        }
        sort(C, C+K, comp);
        for (int i = 0; i < N; i++) {
            A[i].clear(); P[i].clear();
            int k;
            long long e;
            scanf("%d %lld", &k, &e);
            for (int j = 0; j < k; j++) {
                char a;
                double p;
                scanf(" %c %lf %%", &a, &p);
                int pos; for (int l = 0; l < K; l++) if (C[l].ind == a) { pos = l; break; }
                A[i].push_back(pos);
                P[i].push_back((long long)((e*p/100.) + .5 + 1E-13));
            }
        }
        memset(POS,-1,sizeof(POS));
        memset(USED,0,sizeof(USED));
        ret = 0;
        go(0);
        printf("%lld\n", ret);
    }

    return 0;
}

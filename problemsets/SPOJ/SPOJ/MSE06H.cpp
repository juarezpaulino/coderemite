/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define SI(V) (int)(V.size())

typedef vector<int> VI;
typedef pair<int, int> PII;


const int MAXV = 1<<10;

// Habilitar soma em módulo.
const int MOD = 1000000007;

long long SUM_BIT[MAXV];

inline void sum_bit_init() { memset(SUM_BIT, 0, sizeof(SUM_BIT)); }

inline int sum_bit_get(int x) {
    int ret = 0;
    for(int i = x | MAXV; i < 2 * MAXV; i += i & -i)
        ret = (ret + SUM_BIT[i ^ MAXV]); //% MOD;
    return ret;
}

inline int sum_bit_get_interval(int a, int b) {
    return sum_bit_get(a) - sum_bit_get(b+1);
}

inline void sum_bit_add(int x, int v) {
    for(int i = x | MAXV; i; i &= i - 1)
        SUM_BIT[i ^ MAXV] = (SUM_BIT[i ^ MAXV] + v); //% MOD;
}


int T, N, M, K;

vector<PII> C;

int main() {

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &N, &M, &K);
        C.resize(K);
        for (int i = 0; i < K; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            C[i] = PII(x,y);
        }
        sort(C.begin(), C.end());
        long long ret = 0;
        sum_bit_init();
        for (int i = 0; i < K; i++) {
            ret += sum_bit_get(C[i].second + 1);
            sum_bit_add(C[i].second, 1);
        }
        printf("Test case %d: %lld\n", t, ret);
    }


    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int D[1010];

typedef map<int, int> prime_map;

void squeeze(prime_map &M, int &n, int p) { for (; n % p == 0; n /= p) M[p]++; }

prime_map factor(int n) {
    prime_map M;
    if (n < 0) return (factor(-n));
    if (n < 2) return M;

    squeeze(M, n, 2); squeeze(M, n, 3);

    int maxP = min((int)sqrt(n)+2,1000000);
    for (int p = 5; n != 1 && p < maxP; p += 6) { squeeze(M, n, p); squeeze(M, n, p+2); }
    if (n > 1) M[n]++;
    return M;
}


int main() {

    int S, T;
    int id = 1;
    while (scanf("%d %d", &S, &T) && (S|T)) {
        for (int i = 0; i <= T; i++) D[i] = -1;
        queue<int> q;
        q.push(S);
        D[S] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == T) break;
            prime_map M = factor(u);
            for (prime_map::iterator it = M.begin(); it != M.end(); it++) {
                if (it->first == u) continue;
                if (D[u+it->first]==-1) q.push(u+it->first), D[u+it->first] = D[u]+1;
            }
        }
        printf("Case %d: ", id++);
        if (D[T]==-1) puts("-1");
        else printf("%d\n", D[T]);
    }

    return 0;
}

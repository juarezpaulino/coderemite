/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <string>

using namespace std;


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int L, M;
        scanf("%d %d", &L, &M);
        L *= 100;
        queue<int> Q[2];
        for (int i = 0; i < M; i++) {
            int x;
            char s[20];
            scanf("%d %s", &x, s);
            if (s == string("left")) Q[0].push(x);
            else Q[1].push(x);
        }
        int s = 0;
        int ret = 0;
        while (!Q[0].empty() || !Q[1].empty()) {
            if (Q[s].empty()) { ret++; s = 1-s; continue; }
            int c = 0;
            while (!Q[s].empty() && c + Q[s].front() <= L) {
                c += Q[s].front();
                Q[s].pop();
            }
            ret++;
            s = 1-s;
        }
        printf("%d\n", ret);
    }

    return 0;
}

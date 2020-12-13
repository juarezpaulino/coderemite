/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

int S, P;
int X[10101], Y[10101], D[10101];
char V[10101];

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {

    int T;
    T = get_int();
    while (T--) {
        S = get_int();
        P = get_int();
        for (int i = 0; i < P; i++) X[i] = get_int(), Y[i] = get_int(), V[i] = 0, D[i] = 0x3F3F3F3F;
        priority_queue<pair<int,int> > q;
        priority_queue<int> E;
        q.push(make_pair(0,0));
        D[0] = 0;
        while (!q.empty()) {
            pair<int,int> pii = q.top(); q.pop();
            int u = pii.second;
            if (V[u]) continue;
            V[u] = 1;
            E.push(-pii.first);
            for (int i = 0; i < P; i++) if (!V[i] && u != i) {
                int dx = X[u]-X[i];
                int dy = Y[u]-Y[i];
                int d = dx*dx+dy*dy;
                if (d < D[i]) q.push(make_pair(-(D[i] = d), i));
            }
        }
        while (--S && !E.empty()) E.pop();
        double ret = 0;
        if (!E.empty()) ret = sqrt(E.top());
        printf("%.2lf\n", ret+1E-10);
    }

    return 0;
}

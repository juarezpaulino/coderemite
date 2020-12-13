/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <set>

using namespace std;


int main() {

    int T[1010], nt = 0, x;
    while (scanf("%d", &x)) {
        if (!x) break;
        T[nt++] = x;
    }


    int P;
    while (scanf("%d", &P)) {
        if (!P) break;
        int pos[10] = {0};
        map<int,int> mapa;
        set<int> stop, retry;
        int a, b;
        while (scanf("%d %d", &a, &b)) {
            if (!(a+b)) break;
            mapa[a] = b;
            mapa[b] = a;
        }
        while (scanf("%d", &x)) {
            if (!x) break;
            if (x < 0) stop.insert(-x);
            else retry.insert(x);
        }
        int cur = 0;
        int k = 0;
        while (1) {
            if (pos[cur] < 0) { pos[cur] = -pos[cur]; cur = (cur+1)%P; continue; }
            if (pos[cur]+T[k] <= 100) {
                x = pos[cur] += T[k];
                if (stop.count(x)) pos[cur] = -pos[cur];
                else if (retry.count(x)) cur = (cur+P-1)%P;
                else if (mapa.count(x)) pos[cur] = mapa[pos[cur]];
                if (pos[cur] == 100) break;
            }
            k++;
            cur = (cur+1)%P;
        }
        printf("%d\n", cur+1);
    }

    return 0;
}

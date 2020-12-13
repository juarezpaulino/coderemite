/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <set>


using namespace std;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-13;

_inline(int cmp)(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


struct card {
    int val; char naipe;
    card(int val = 0, char naipe = 0): val(val), naipe(naipe) {}
    bool operator <(card y) const {
        if (val > y.val) return true; if (val < y.val) return false;
        if (naipe > y.naipe) return true; return false;
    }
};

int p, n, m;
multiset<card> joga[10];
card saque[300]; int pos;
card topo;
int sent, vez;

void atualizar(card last) {
    if (last.val==12) sent = -sent;
    else if (last.val==7) {
        vez = (vez+p+sent)%p;
        joga[vez].insert(saque[pos]); joga[vez].insert(saque[pos+1]); pos+=2;
    }
    else if (last.val==1) {
        vez = (vez+p+sent)%p;
        joga[vez].insert(saque[pos++]);
    }
    else if (last.val==11) vez = (vez+p+sent)%p;
}


int main() {

    register int i, j;
    int val; char ch, novo;
    set<card>::iterator it;

    while (scanf("%d %d %d", &p, &m, &n)) {
        if (!p && !m && !n) break;
        for (i = 0; i < p; i++) {
            joga[i].clear();
            for (j = 0; j < m; j++) {
                scanf("%d %c", &val, &ch); joga[i].insert(card(val, ch));
            }
        }
        scanf("%d %c", &val, &ch); topo = card(val, ch);
        for (i = 0, n-=p*m+1; i < n; i++) {
            scanf("%d %c", &val, &ch); saque[i] = card(val, ch);
        }
        //for (i = 0; i < p; i++) foreach(it, all(joga[i]))
          //  printf("vez[%d] %d %c\n", i, it->val, it->naipe);
        sent = 1; pos = 0; vez = p-1; novo = 0;
        atualizar(topo);
        vez = (topo.val==12)?0:(vez+p+sent)%p;
        while (1) {
            for (it = joga[vez].begin(); it != joga[vez].end(); it++)
                if (it->val == topo.val || it->naipe == topo.naipe) {
                    topo = *it; joga[vez].erase(it); novo = 1;
                    break;
                }
            if (!joga[vez].size()) break;
            if (it == joga[vez].end()) {
                if (saque[pos].val==topo.val || saque[pos].naipe==topo.naipe) {
                    topo = saque[pos++]; novo = 1;
                }
                else joga[vez].insert(saque[pos++]);
            }
            if (novo) { atualizar(topo); novo = 0; }
            vez = (vez+p+sent)%p;
        }
        printf("%d\n", vez+1);
    }

    return 0;
}


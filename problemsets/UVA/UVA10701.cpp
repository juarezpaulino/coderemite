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

char P[60], I[60];
int N, K;

struct node { char k; node *l, *r; };

node *T;

node *build_tree(int lin, int rin) {
    if (lin > rin) return NULL;
    node *t = new node;
    t->k = P[K++];
    int p;
    for (p = lin; p <= rin; p++) if (I[p]==t->k) break;
    t->l = build_tree(lin,p-1);
    t->r = build_tree(p+1,rin);
    return t;
}

void postorder(node *T) {
    if (!T) return;
    postorder(T->l);
    postorder(T->r);
    putchar(T->k);
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %s %s", &N, P, I);
        K = 0;
        T = build_tree(0,N-1);
        postorder(T);
        putchar('\n');
    }

    return 0;
}
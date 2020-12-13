/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

struct node {
    int v;
    node *l, *r;
};

int pos;
vector<int> in, post;
char S[101010];

node *buildTree(int l, int r) {
    if (l > r) return 0;
    node *u = new node();
    u->v = post[pos--];
    int k;
    for (int i = l; i <= r; i++) if (u->v == in[i]) {
        k = i;
        break;
    }
    u->r = buildTree(k+1, r);
    u->l = buildTree(l, k-1);
    return u;
}

int mini, leaf;

void go(node *u, int v) {
    v += u->v;
    if (!u->l && !u->r) {
        if (v < mini) {
            mini = v;
            leaf = u->v;
        }
        if (v == mini) leaf = min(leaf, u->v);
    }
    if (u->l) go(u->l, v);
    if (u->r) go(u->r, v);
}


int main() {

    while (gets(S)) {
        in.clear();
        post.clear();
        int x;
        {
            istringstream is(S);
            while (is >> x) in.push_back(x);
        }
        gets(S);
        {
            istringstream is(S);
            while (is >> x) post.push_back(x);
        }
        pos = in.size()-1;
        node *root = buildTree(0, in.size()-1);
        mini = 1E9;
        go(root, 0);
        printf("%d\n", leaf);
    }

    return 0;
}

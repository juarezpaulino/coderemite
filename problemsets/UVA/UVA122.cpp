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

struct Node {
    int v; Node *L, *R;
    Node(int v = -1, Node *L = NULL, Node *R = NULL) : v(v), L(L), R(R) {}
};

Node *T;

char S[100], P[100];
bool complete;

Node *add(Node *T, int v, char *P) {
    if (!*P) {
        if (T && T->v != -1) complete = false;
        if (!T) T = new Node(v);
        else T->v = v;
        return T;
    }

    if (!T) T = new Node();
    if (*P=='L') T->L = add(T->L, v, P+1);
    else T->R = add(T->R, v, P+1);
    return T;
}

vector<int> RET;

int main() {

    while (1) {
        T = 0;
        complete = true;
        while (1) {
            if (scanf("%s", S)==EOF) return 0;
            if (!strcmp(S,"()")) break;
            int v;
            *P = 0;
            sscanf(S, "(%d,%[^)])", &v, P);
            T = add(T, v, P);
        }
        if (!T || !complete) { puts("not complete"); continue; }
        RET.clear();
        queue<Node *> Q;
        Q.push(T);
        while (!Q.empty()) {
            Node *u = Q.front(); Q.pop();
            if (u->v == -1) complete = false;
            RET.push_back(u->v);
            if (u->L) Q.push(u->L);
            if (u->R) Q.push(u->R);
        }
        if (!complete) { puts("not complete"); continue; }
        printf("%d", RET[0]);
        for (int i = 1; i < RET.size(); i++) printf(" %d", RET[i]);
        putchar('\n');
    }

    return 0;
}

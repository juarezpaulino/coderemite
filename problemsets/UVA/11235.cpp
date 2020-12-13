/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
///////////////////////////////////////////////////////////////////////////////
// Segment Tree 1
//
// - Mounted like a heap structure Nodes from 1 .. 2^(logN + 1)
// - Values on V[0..N-1];
// - Node 1 represents all interval (1..N);
//   Node 2 represents interval (1..N/2)
//   Node 3 represents interval (N/2+1 .. N)
//   ...
// - We have leaf on recursion when A == B.
//
// * Functions:
// 1) merge: Have calculated for two children, combine it into parent (specific to problem).
// 2) init: First configuration of the tree from V[] values. Call with init(1, 1, N) (trivial)
// 3) query: Query for a specific interval A..B by searching on the original tree. Call with query(1, 1, N, A, B) (trivial)
// 4) update: Updates for a specific node v value the node with key identifier. Call with update(1, 1, N, p, v) (trivial)
//
///////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

const int INF = 1<<30;

typedef pair<int,int> PII;

const PII NULO = PII(-INF, -INF);

struct node {
    // represent sum of "init", "end", "all" segment.
    // pair = (value, count).
    PII V[3];
    node(PII A = NULO, PII B = NULO, PII C = NULO) {
        V[0] = A; V[1] = B; V[2] = C;
    }
};

node tree[1<<18 + 1];

int N;
int V[100000];


void merge(node &A, node &B, node &C) {
    // Find init segment.
    A.V[0] = B.V[0];
    if (B.V[1].first == B.V[0].first && B.V[1].first == C.V[0].first) A.V[0].second += C.V[0].second;

    // Find end max segment.
    A.V[1] = C.V[1];
    if (C.V[1].first == C.V[0].first && C.V[1].first == B.V[1].first) A.V[1].second += B.V[1].second;

    // Find all max sum.
    if (B.V[2] == NULO) A.V[2] = C.V[2];
    else if (C.V[2] == NULO) A.V[2] = B.V[2];
    else {
        A.V[2] = B.V[2];
        if (A.V[2].second < C.V[2].second) A.V[2] = C.V[2];
        if (B.V[1].first == C.V[0].first &&
            B.V[1].second + C.V[0].second > A.V[2].second)
            A.V[2].first = C.V[0].first, A.V[2].second = B.V[1].second+C.V[0].second;
    }
}

void init(int p, int a, int b) {
	// We are on a leaf node.
    if (a == b) {
        for (int i = 0; i < 3; i++) {
            tree[p].V[i].first = V[a-1];
            tree[p].V[i].second = 1;
        }
        return;
    }
    // Visit children.
    int m = (a+b) / 2, l = p*2, r = l+1;
    init(l, a, m);
    init(r, m+1, b);
    // Compose parent from children.
    merge(tree[p], tree[l], tree[r]);
}

// Return a node representing the max sum on segment from A to B.
node query(int p, int a, int b, int A, int B) {
    node ret(NULO, NULO, NULO);
    // Segment does not intersect.
    if (B < a || A > b) return ret;
    // Segmented is contained.
    if (A <= a && b <= B) return tree[p];
    // Query children.
    int m = (a+b) / 2, l = p*2, r = l+1;
    node S[2] = {
        query(l, a, m, A, B),
        query(r, m+1, b, A, B)
    };
    // Compose parent query.
    merge(ret, S[0], S[1]);
    return ret;
}

// Updates tree on value key with a specific value.
void update(int p, int a, int b, int key, node &v) {
    // Reach leaf node.
    if (a == b) {
        tree[p] = v;
        return;
    }
    int m = (a+b) / 2, l = p*2, r = l+1;
    if (key <= m) update(l, a, m, key, v);
    else update(r, m+1, b, key, v);
    merge(tree[p], tree[l], tree[r]);
}


int main() {

    int N, Q;
    while (scanf("%d %d", &N, &Q)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        init(1,1,N);
        while (Q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            node ret = query(1,1,N,a,b);
            printf("%d\n", ret.V[2].second);
        }
    }

    return 0;
}

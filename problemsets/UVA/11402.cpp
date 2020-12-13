/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>

using namespace std;


const int MAX = (1<<21)+1;

struct data {
    int x, y;
    char lazy;
    data operator+(const data &B) {
        data ret = *this;
        ret.x += B.x;
        ret.y += B.y;
        ret.lazy = 0;
        return ret;
    }
};

string V;
data tree[MAX];

void lazy_set(int node, char lazy) {
    if (lazy == 'I') {
        if (tree[node].lazy == 'I') tree[node].lazy = 0;
        else if (tree[node].lazy == 'E') tree[node].lazy = 'F';
        else if (tree[node].lazy == 'F') tree[node].lazy = 'E';
        else tree[node].lazy = 'I';
    }
    else tree[node].lazy = lazy;
}

void lazy_change(int node, int a, int b) {
    if (tree[node].lazy == 0) return;

    int l = node*2,
        r = node*2+1;

    if (tree[node].lazy == 'E') {
        tree[node].x += tree[node].y;
        tree[node].y = 0;
    }
    else if (tree[node].lazy == 'F') {
        tree[node].y += tree[node].x;
        tree[node].x = 0;
    }
    else if (tree[node].lazy == 'I') {
        swap(tree[node].y,tree[node].x);
    }

    if (a != b) {
        lazy_set(l,tree[node].lazy);
        lazy_set(r,tree[node].lazy);
    }

    tree[node].lazy = 0;
}

void build_tree(int node, int a, int b) {
    int l = node*2,
        r = node*2+1;

  	if(a > b) return;

  	if(a == b) {
        tree[node] = (V[a-1]=='0')?(data){1,0,0}:(data){0,1,0};
		return;
	}

	build_tree(l, a, (a+b)/2);
	build_tree(r, 1+(a+b)/2, b);

	tree[node] = tree[l]+tree[r];
}

void update_tree(int node, int a, int b, int i, int j, char v) {
    int l = node*2,
        r = node*2+1;

	if(a > b) return;

  	if(a >= i && b <= j) lazy_set(node, v);

    lazy_change(node, a, b);

    if (a > j || b < i) return;
    if (a >= i && b <= j) return;

	update_tree(l, a, (a+b)/2, i, j, v);
	update_tree(r, 1+(a+b)/2, b, i, j, v);

    tree[node] = tree[l] + tree[r];
}

data query_tree(int node, int a, int b, int i, int j) {
    int l = node*2,
        r = node*2+1;

    lazy_change(node, a, b);

	if(a > b || a > j || b < i) return (data){0,0,0};

	if(a >= i && b <= j) return tree[node];

	data q1 = query_tree(l, a, (a+b)/2, i, j);
	data q2 = query_tree(r, 1+(a+b)/2, b, i, j);

	tree[node] = tree[l]+tree[r];

	return q1+q2;
}



int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case %d:\n", t);
        int M;
        scanf("%d", &M);
        V = "";
        int id = 1;
        while (M--) {
            int u;
            char S[1010];
            scanf("%d", &u);
            scanf("%s", S);
            for (int i = 0; i < u; i++) V += S;
        }
        int N = V.size();
        build_tree(1,1,N);
        int Q;
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
            char c;
            int a, b;
            scanf(" %c %d %d", &c, &a, &b);
            a++; b++;
            if (c == 'F') { update_tree(1,1,N,a,b,'F'); }
            if (c == 'E') { update_tree(1,1,N,a,b,'E'); }
            if (c == 'I') { update_tree(1,1,N,a,b,'I'); }
            if (c == 'S') {
                data d = query_tree(1,1,N,a,b);
                printf("Q%d: %d\n", id++, d.y);
            }
        }
    }

    return 0;
}

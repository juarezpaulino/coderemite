/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = (1<<18)+1;

struct data {
    int x, y, z;
    data operator+(const data &B) {
        data ret = *this;
        ret.x += B.x;
        ret.y += B.y;
        ret.z += B.z;
        return ret;
    }
};

data tree[MAX];
int lazy[MAX];

void build_tree(int node, int a, int b) {
    int l = node*2,
        r = node*2+1;

  	if(a > b) return;

  	if(a == b) {
        tree[node] = (data){1,0,0};
        lazy[node] = 0;
		return;
	}

	build_tree(l, a, (a+b)/2);
	build_tree(r, 1+(a+b)/2, b);

	tree[node]= tree[l]+tree[r];
	lazy[node] = 0;
}

void update_tree(int node, int a, int b, int i, int j) {
    int l = node*2,
        r = node*2+1;

  	if(lazy[node] != 0) {
  	    if (lazy[node]%3==1)          swap(tree[node].x, tree[node].y), swap(tree[node].x, tree[node].z);
  	    else if (lazy[node]%3 == 2)   swap(tree[node].x, tree[node].z), swap(tree[node].x, tree[node].y);

		if(a != b) {
			lazy[l]+=lazy[node];
            lazy[r]+=lazy[node];
		}
   		lazy[node] = 0;
  	}

	if(a > b || a > j || b < i)
		return;

  	if(a >= i && b <= j) {
        swap(tree[node].x, tree[node].y), swap(tree[node].x, tree[node].z);
		if(a != b) {
			lazy[l]++;
			lazy[r]++;
		}
        return;
	}

	update_tree(l, a, (a+b)/2, i, j);
	update_tree(r, 1+(a+b)/2, b, i, j);

	tree[node]= tree[l]+tree[r];
}

data query_tree(int node, int a, int b, int i, int j) {
    int l = node*2,
        r = node*2+1;

	if(a > b || a > j || b < i) return (data){0,0,0};

	if(lazy[node] != 0) {
  	    if (lazy[node]%3==1)          swap(tree[node].x, tree[node].y), swap(tree[node].x, tree[node].z);
  	    else if (lazy[node]%3 == 2)   swap(tree[node].x, tree[node].z), swap(tree[node].x, tree[node].y);

		if(a != b) {
			lazy[l]+=lazy[node];
            lazy[r]+=lazy[node];
		}
   		lazy[node] = 0;
	}

	if(a >= i && b <= j)
		return tree[node];

	data q1 = query_tree(node*2, a, (a+b)/2, i, j);
	data q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);

	data ret = q1 + q2;

	return ret;
}


int main() {

    int N, M;
    while (scanf("%d %d ", &N, &M) != EOF) {

        build_tree(1,0,N-1);
        while (M--) {
            char c;
            int A, B;
            scanf("%c %d %d ", &c, &A, &B);
            if (c == 'M') update_tree(1,0,N-1,A-1,B-1);
            else {
                data ret = query_tree(1,0,N-1,A-1,B-1);
                printf("%d %d %d\n", ret.x, ret.y, ret.z);
            }
        }
        putchar('\n');
    }

    return 0;
}

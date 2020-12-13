/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

bool YES;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)


const int MAXD = 10;

struct Trie {
    int count;
    Trie *next[MAXD];
};

// Return new node.
Trie *trie_new() {
	Trie *t = new Trie;
	FOR(i,0,MAXD) t->next[i] = NULL;
	t->count = 0;
	return t;
}

// Delete entire trie if passed a pointer for root.
void trie_delete(Trie *R) {
	if (R) {
	    FOR(i,0,MAXD) trie_delete(R->next[i]);
		delete(R);
	}
}

// Add node by running word from root until reach some leaf.
void trie_add(Trie *R, char *W) {
    bool last = 1;
    while (*W) {
        int v = *W-'0';
        if (R->count) { YES = 0; break; }
        if (!R->next[v]) R->next[v] = trie_new(), last = 1;
        else last = 0;
        R = R->next[v];
        W++;
	}
	if (!last) YES = 0;
	R->count++;
}



int main() {

    int T; scanf("%d", &T);
    while (T--) {
        int N;
        char S[15];
        scanf("%d", &N);
        Trie *R = trie_new();
        YES = 1;
        for (int i = 0; i < N; i++) {
            scanf("%s", S);
            if (YES) trie_add(R, S);
        }
        if (YES) puts("YES");
        else puts("NO");
        //trie_delete(R);
    }

    return 0;
}

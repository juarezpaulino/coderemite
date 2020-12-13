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

struct seq {
    string s;
    int o;
    int p;
};

int T;
seq S[100];
int N, M;

int mergecount(string &A) {
    int N = A.size();
    if (N <= 1) return 0;
    string B(A.begin(), A.begin()+N/2),
           C(A.begin()+N/2, A.end());
    int ret = mergecount(B) + mergecount(C);
    int i, j, k;
    for (i = j = k = 0; k < N; k++) {
        if (j == C.size()) A[k] = B[i++];
        else if (i == B.size()) A[k] = C[j++];
        else if (B[i] <= C[j]) A[k] = B[i++];
        else A[k] = C[j++], ret += N/2-i;
    }
    return ret;
}

bool comp(const seq &A, const seq &B) {
    if (A.o != B.o) return A.o < B.o;
    return A.p < B.p;
}

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &M, &N);
        for (int i = 0; i < N; i++) {
            char s[100];
            scanf("%s", s);
            string aux = S[i].s = s;
            S[i].o = mergecount(aux);
            S[i].p = i;
        }
        sort(S, S+N, comp);
        for (int i = 0; i < N; i++) printf("%s\n", S[i].s.c_str());
        if (T) putchar('\n');
    }

    return 0;
}

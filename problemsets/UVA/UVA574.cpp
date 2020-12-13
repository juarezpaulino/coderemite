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

int T, N;
int V[30];

struct comp {
    bool operator()(const vector<int> A, const vector<int> B) const {
        int i, j;
        for (i = j = 0; i < A.size() && j < B.size(); i++, j++)
            if (A[i] != B[j]) return A[i] > B[j];
        if (j < B.size()) return true;
        return false;
    }
};

set<vector<int>, comp> S;

int main() {

    while (scanf("%d %d", &T, &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        sort(V, V+N, greater<int>());
        printf("Sums of %d:\n", T);
        bool found = false;
        S.clear();
        for (int i = 1; i < (1<<N); i++) {
            int t = 0;
            vector<int> RET;
            for (int j = 0; j < N; j++) if (i&(1<<j)) t += V[j], RET.push_back(V[j]);
            if (t == T && !S.count(RET)) {
                S.insert(RET);
                found = true;
            }
        }
        if (!found) puts("NONE");
        else {
            for (set<vector<int> >::iterator it = S.begin(); it != S.end(); it++) {
                vector<int> RET = *it;
                bool f = false;
                for (int j = 0; j < RET.size(); j++) {
                    if (f) putchar('+');
                    f = true;
                    printf("%d", RET[j]);
                }
                putchar('\n');

            }
        }
    }

    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

pair<int, int> V[300];

bool comp(const pair<int, int> &A, const pair<int, int> &B) {
    if (!A.second) return false;
    if (!B.second) return true;
    if (A.second != B.second) return A.second < B.second;
    return A.first > B.first;
}

int main() {

    char S[1010];
    bool f = false;
    while (gets(S)) {
        if (f) putchar('\n');
        f = true;
        for (int i = 0; i < 300; i++) V[i].first = i, V[i].second = 0;
        for (int i = 0; S[i]; i++) V[S[i]].second++;
        sort(V, V+300, comp);
        for (int i = 0; V[i].second > 0; i++) {
            printf("%d %d\n", V[i].first, V[i].second);
        }
    }

    return 0;
}

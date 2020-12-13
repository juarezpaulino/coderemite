/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <cctype>

using namespace std;

struct comp {
bool operator()(const pair<int,string> &A, const pair<int,string> &B) const {
    if (A.first != B.first) return A.first > B.first;
    return A.second > B.second;
}
};


int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        int m, n, b, k;
        map<string,int> P;
        char S[1010], s[1010];

        gets(S);
        for (int i = 0; S[i]; i++) S[i] = toupper(S[i]);

        scanf("%d %d %d ", &m, &n, &b);
        for (int i = 0; i < m; i++) {
            int p;
            scanf("%s %d ", s, &p);
            if (!P.count(s)) P[s] = p;
            else P[s] = min(P[s], p);
        }

        priority_queue<pair<int, string>, vector<pair<int,string> >, comp > q;
        for (int i = 0; i < n; i++) {
            int t = 0;
            char v[1010];
            int u;
            gets(v);
            scanf("%d", &k);
            while (k--) {
                scanf("%s %d ", s, &u);
                t += P[s]*u;
            }
            if (t <= b) q.push(make_pair(t, v));
        }

        puts(S);
        if (q.empty()) { puts("Too expensive!"); }
        else while (!q.empty()) {
            puts(q.top().second.c_str());
            q.pop();
        }
        putchar('\n');
    }

    return 0;
}

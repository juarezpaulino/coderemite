/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct comp {
    bool operator()(const pair<int,int> &A, const pair<int,int> &B) const {
        if (A.first != B.first) return A.first > B.first;
        return A.second > B.second;
    }
};


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int P;
        char S[10101];
        scanf("%d ", &P);
        priority_queue<pair<int,int>, vector<pair<int,int> >, comp> q;
        for (int i = 1; i <= P; i++) {
            gets(S);
            istringstream is(S);
            int c = 0, x;
            while (is >> x) c++;
            q.push(make_pair(c,i));
        }
        int v = q.top().first;
        bool first = 1;
        while (!q.empty() && q.top().first == v) {
            if (first) printf("%d", q.top().second);
            else printf(" %d", q.top().second);
            first = 0;
            q.pop();
        }
        putchar('\n');
    }

    return 0;
}

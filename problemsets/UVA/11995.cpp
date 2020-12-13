/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;


int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> p;
        bool sok = 1, qok = 1, pok = 1;
        while (N--) {
            int t, x;
            scanf("%d %d", &t, &x);
            if (t == 1) {
                if (sok) s.push(x);
                if (qok) q.push(x);
                if (pok) p.push(x);
            }
            else {
                if (sok) {
                    if (s.empty()) sok = 0;
                    else { int y = s.top(); if (x != y) sok = 0; s.pop(); }
                }
                if (qok) {
                    if (q.empty()) qok = 0;
                    else { int y = q.front(); if (x != y) qok = 0; q.pop(); }
                }
                if (pok) {
                    if (p.empty()) pok = 0;
                    else { int y = p.top(); if (x != y) pok = 0; p.pop(); }
                }
            }
        }
        int c = sok + qok + pok;
        if (!c) puts("impossible");
        else if (c > 1) puts("not sure");
        else if (sok) puts("stack");
        else if (qok) puts("queue");
        else puts("priority queue");

    }

    return 0;
}

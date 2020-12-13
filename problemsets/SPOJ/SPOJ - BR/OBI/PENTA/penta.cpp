/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <queue>
#include <map>
#include <list>

#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define INF 0x3F3F3F3F

using namespace std;

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {

    int n, p, joga[10000];
    list<int> pos[24];
    char in[24];
    register int i, j, k, mini, c = 1;
    priority_queue<pair<int, int> > q;
    
    while (1) {
        n = get_int(); p = get_int(); if (!n && !p) break;
        for (i = 1; i <= 23; i++) { in[i] = 0; pos[i].clear(); }
        for (i = 0; i < n; i++) joga[i] = get_int();
        for (i = k = 0; i < n; i++) 
            if (!in[joga[i]]) { k++; if (k > p) break; in[joga[i]] = 1; }
        if (i == n) { printf("Teste %d\n0\n\n", c++); continue; }
        while (!q.empty()) q.pop();
        for (j = i; j < n; j++) pos[joga[j]].push_back(j);
        for (j = 1; j <= 23; j++) if (in[j]) {
            if (!pos[j].empty()) q.push(make_pair(pos[j].front(), j));
            else q.push(make_pair(INF, j));
        }
        
        mini = 0;
        while (i < n) {
            pos[joga[i]].pop_front(); 
            if (in[joga[i]]) {
                if (!pos[joga[i]].empty()) q.push(make_pair(pos[joga[i]].front(), joga[i]));
                else q.push(make_pair(INF, joga[i]));
                i++;
                continue;
            }
            while (q.top().first < i) q.pop();
            mini++; in[q.top().second] = 0; q.pop(); in[joga[i]] = 1;
            if (!pos[joga[i]].empty()) q.push(make_pair(pos[joga[i]].front(), joga[i]));
            else q.push(make_pair(INF, joga[i]));
            i++;
        }
        printf("Teste %d\n%d\n\n", c++, mini);
    }
    
    return 0;
}


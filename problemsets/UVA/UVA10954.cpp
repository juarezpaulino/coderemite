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

int N;

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < N; i++) {
            int x; scanf("%d", &x);
            q.push(x);
        }
        int ret = 0;
        while (q.size() != 1) {
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            ret += x+y;
            q.push(x+y);
        }
        printf("%d\n", ret);
    }

    return 0;
}

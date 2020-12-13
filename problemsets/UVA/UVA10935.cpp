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
#include <numeric>

using namespace std;

int N;

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        queue<int> q;
        for (int i = 1; i <= N; i++) q.push(i);
        printf("Discarded cards:");
        while (q.size() > 2) {
            printf(" %d,", q.front()); q.pop();
            q.push(q.front()); q.pop();
        }

        if (q.size() == 2) printf(" %d\n", q.front()), q.pop();
        else putchar('\n');

        printf("Remaining card: %d\n", q.front());
    }

    return 0;
}

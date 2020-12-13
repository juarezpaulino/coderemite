/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    for (int i = 1; i <= N; i++) {
        int c = 0, x;
        for (int j = 0; j < M; j++) scanf("%d", &x), c += x;
        q.push(make_pair(c, i));
    }
    printf("%d\n", q.top().second); q.pop();
    printf("%d\n", q.top().second); q.pop();
    printf("%d\n", q.top().second); q.pop();

    return 0;
}

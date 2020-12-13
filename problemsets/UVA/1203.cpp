/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    char S[101];
    priority_queue<pair<int,int> > q;
    map<int,int> B;
    while (scanf("%s", S)!=EOF && string(S) != "#") {
        int a, b;
        scanf("%d %d", &a, &b);
        q.push(make_pair(-b, -a));
        B[a] = b;
    }
    int K;
    scanf("%d", &K);
    while (K--) {
        int a = -q.top().second, b = -q.top().first;
        q.pop();
        q.push(make_pair(-b-B[a], -a));
        printf("%d\n", a);
    }

    return 0;
}

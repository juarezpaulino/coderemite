/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

int main() {

    int N, K;
    scanf("%d %d", &N, &K);
    vector<PII> V[2];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) V[1].push_back(PII(i,j));
    int novo, old;
    for (int i = 0; i < K; i++) {
        novo = i%2, old = 1-novo;
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        V[novo].clear();
        for (int k = 0; k < V[old].size(); k++)
            if (abs(V[old][k].first - x) + abs(V[old][k].second - y) == d)
                V[novo].push_back(V[old][k]);
    }
    if (V[novo].size() == 1) printf("%d %d\n", V[novo][0].first, V[novo][0].second);
    else puts("-1 -1");

    return 0;
}

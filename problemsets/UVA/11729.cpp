/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <map>
#include <functional>
#include <vector>

using namespace std;

int main() {

    int N;
    int id = 1;
    while (scanf("%d", &N) && N) {
        vector<pair<int,int> > V;
        for (int i = 0; i < N; i++) {
            int b, j;
            scanf("%d %d", &b, &j);
            V.push_back(make_pair(j,b));
        }
        sort(V.begin(), V.end(), greater<pair<int,int> >());
        int ret = 0, t = V[0].first;
        for (int i = 0; i < N; i++) {
            ret += V[i].second;
            if (i) t -= V[i].second;
            t = max(t, V[i].first);
        }
        ret += t;
        printf("Case %d: %d\n", id++, ret);
    }

    return 0;
}

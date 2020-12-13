/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

    int k;
    while (scanf("%d", &k) != EOF) {
        vector<pair<int,int> > ret;
        for (int y = k+1; y <= 2*k; y++) {
            long long v = k*(long long)y;
            if (v % (y - k) == 0) ret.push_back(make_pair((int)(v / (y-k)), y));
        }
        printf("%d\n", ret.size());
        for (int i = 0; i < ret.size(); i++) {
            int x = ret[i].first, y = ret[i].second;
            printf("1/%d = 1/%d + 1/%d\n", k, x, y);
        }
    }

    return 0;
}

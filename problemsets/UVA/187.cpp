/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string C[1010];

int main() {

    int id;
    char S[110];
    while (scanf(" %3d%[^\n]", &id, S)) {
        if (id == 0) break;
        C[id] = S;
    }

    vector<pii> R;
    int x, y, v;
    ll ret = 0;
    id = -1;
    while (scanf("%3d%3d %d", &x, &y, &v)) {
        if (x != id) {
            if (ret != 0) {
                printf("*** Transaction %3d is out of balance ***\n", id);
                for (int i = 0; i < R.size(); i++)
                    printf("%3d %-30s %10.2lf\n", R[i].first, C[R[i].first].c_str(), R[i].second/100.);
                printf("999 Out of Balance                 %10.2lf\n\n", fabs(ret)/100.);
            }
            id = x;
            R.clear();
            ret = 0;
        }
        if (!x) break;
        R.push_back(make_pair(y, v));
        ret += v;
    }

    return 0;
}

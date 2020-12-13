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

int main() {

    while (1) {
        vector<int> V;
        int x;
        while (scanf("%d", &x)) {
            if (x == 0) break;
            V.push_back(x);
        }
        if (V.size() == 0) break;
        int i, f = 0;
        for (i = 0; i <= 18000; i++) {
            bool ok = 1;
            for (int j = 0; j < V.size(); j++) {
                if (i%(2*V[j]) >= V[j]-5) ok = 0;
            }
            if (ok) {
                if (f == 1) break;
            }
            else f = 1;
        }
        if (i > 18000) { puts("Signals fail to synchronise in 5 hours"); continue; }
        printf("%02d", i/3600); i %= 3600;
        printf(":%02d", i/60); i %= 60;
        printf(":%02d\n", i);
    }

    return 0;
}

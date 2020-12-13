/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        vector<int> A;
        int x;
        while (scanf("%d", &x) && x) {
            A.push_back(x);
        }
        sort(A.begin(), A.end(), greater<int>());
        int ret = 0;
        bool ok = 1;
        for (int i = 0; i < A.size() && ok; i++) {
            if (A[i] > 5000000) ok = 0;
            int u = 1;
            for (int j = 0; j <= i; j++) if ((u *= A[i]) > 5000000) { ok = 0; break; }
            ret += 2*u;
            if (ret > 5000000) ok = 0;
        }
        if (!ok) puts("Too expensive");
        else printf("%d\n", ret);
    }

    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int K;
    while (scanf("%d", &K) != EOF) {
        vector<int> ret;
        int p = 1;
        for (p = 0; p*p < (int)(pow(10.,K)+1E-10); p++) {
            for (int i = 0; i <= p; i++) {
                if ((int)(i*pow(10.,K/2)+1E-9+p-i) == p*p)
                    ret.push_back(p*p);
            }
        }
        sort(ret.begin(), ret.end());
        if (K == 2) for (int i = 0; i < ret.size(); i++) printf("%02d\n", ret[i]);
        if (K == 4) for (int i = 0; i < ret.size(); i++) printf("%04d\n", ret[i]);
        if (K == 6) for (int i = 0; i < ret.size(); i++) printf("%06d\n", ret[i]);
        if (K == 8) for (int i = 0; i < ret.size(); i++) printf("%08d\n", ret[i]);
    }
    return 0;
}

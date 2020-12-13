/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<int> V;
    V.push_back(1);
    V.push_back(2);
    int M = 1;
    while (V[M] < 100000000) { V.push_back(V[M] + V[M-1]); M++; }
    int N, K;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        string ret;
        int l = -1;
        int k = K;
        while (K) {
            int v = (int)(upper_bound(V.begin(), V.end(), K) - V.begin()) - 1;
            if (l != -1) for (int i = l-1; i > v; i--) ret += "0";
            ret += "1";
            K -= V[v];
            l = v;
        }
        if (l != -1) for (int i = l-1; i >= 0; i--) ret += "0";
        printf("%d = %s (fib)\n", k, ret.c_str());
    }

    return 0;
}

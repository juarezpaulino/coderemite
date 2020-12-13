/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }


int main() {

    int N, T;
    int V[50];
    while (scanf("%d %d", &N, &T) != EOF) {
        if (!(N|T)) break;
        vector<int> mmc;
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) for (int k = j+1; k < N; k++) for (int l = k+1; l < N; l++) {
            int v = lcm(V[i], lcm(V[j], lcm(V[k], V[l])));
            mmc.push_back(v);
        }

        while (T--) {
            int y; scanf("%d", &y);
            int maxi = 0, mini = 1<<30;

            for (int i = 0; i < mmc.size(); i++) {
                maxi = max(maxi, y/mmc[i]*mmc[i]);
                mini = min(mini, (y%mmc[i]==0) ? y/mmc[i]*mmc[i] : (y/mmc[i]+1)*mmc[i]);
            }

            printf("%d %d\n", maxi, mini);
        }
    }

    return 0;
}

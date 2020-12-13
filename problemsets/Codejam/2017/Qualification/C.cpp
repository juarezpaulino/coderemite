/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll go(ll N, ll K) {
    if (K==1) return N;
    if (N%2==0 && K%2) return go((N-1)>>1, K>>1);
    return go(N>>1, K>>1);
}


int main() {

    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d: ", tt);

        ll N, K;
        cin >> N >> K;
        N = go(N,K);
        cout << (N>>1) << " " << ((N-1)>>1) << endl;
    }
    return 0;
}

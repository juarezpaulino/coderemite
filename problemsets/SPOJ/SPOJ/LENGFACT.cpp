/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
///////////////////////////////////////////////////////////////////////////////
// Stirling Formula: ln N! = N * lnN - N + ln(2*PI*N)/2
//                      N! ~ sqrt(2*PI*N) (N / e) ^ N
//
///////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

long long T, M;

int main() {

    cin >> T;
    while (T--) {
        cin >> M;
        if (M <= 1) { puts("1"); continue; }
        double N = M;
        long long ret = (N*log(N) - N + log(2*M_PI*N)/2) / log(10) + 1.;
        cout << ret << endl;
    }

    return 0;
}

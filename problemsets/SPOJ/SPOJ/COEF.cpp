/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int K, N;

int fact(int N) { return N<=1 ? 1 : N*fact(N-1); }

int main() {

    while (cin >> N >> K) {
        int ret = fact(N);
        for (int i = 0; i < K; i++) { int x; cin >> x; ret /= fact(x); }
        cout << ret << endl;
    }
    return 0;
}

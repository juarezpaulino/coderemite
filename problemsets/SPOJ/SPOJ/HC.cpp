/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int T, N;

int main() {

    cin >> T;
    while (T--) {
        cin >> N;
        int ret = 0;
        for (int i = 0; i < N; i++) {
            string coin;
            cin >> coin;
            if (coin == "lxh") ret++;
        }
        if (ret&1) puts("lxh");
        else puts("hhb");
    }

    return 0;
}

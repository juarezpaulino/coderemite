/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>

using namespace std;

int T, N, M;

int main() {

    cin >> T;
    while (T--) {
        cin >> N >> M;
        if (M >= N) {
            if (N%2==1) puts("R");
            else puts("L");
        }
        else {
            if (M%2==1) puts("D");
            else puts("U");
        }

    }

    return 0;
}

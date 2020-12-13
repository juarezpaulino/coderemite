/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>

using namespace std;


int T;

int main() {

    int N, K, E;
    cin >> T;
    while (T--) {
        int v;
        cin >> N >> K >> v >> E;
        cout << E + (E-N) / (K-1) << endl;
    }

    return 0;
}

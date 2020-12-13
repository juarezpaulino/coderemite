/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;
    int k = 2;
    int ret = N;
    while (N >= k*k) {
        ret += (N-k*k+k)/k;
        k++;
    }
    cout << ret << endl;
    return 0;
}

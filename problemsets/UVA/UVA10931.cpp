/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string binary(int N) {
    string ret;
    while (N) { ret = string(1, (N%2)+'0') + ret; N/=2; }
    return ret;
}

int main() {

    int I;
    while (scanf("%d", &I)) {
        if (!I) break;
        printf("The parity of %s is %d (mod 2).\n", binary(I).c_str(), __builtin_popcount(I));
    }

    return 0;
}

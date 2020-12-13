/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main() {

    char S[20];
    while (gets(S)) {
        string a = S, b = S;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<char>());
        int k = 0;
        while (a[k] == '0') k++;
        if (k != 0) swap(a[0], a[k]);
        long long A = atol(a.c_str()), B = atol(b.c_str());
        printf("%lld - %lld = %lld = 9 * %lld\n", B, A, B-A, (B-A)/9);
    }

    return 0;
}

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

int main() {

    int T;
    char A[101], B[10101];
    scanf("%d", &T);
    while (T--) {
        scanf("%s %s", A, B);
        string a = A, b = B, arev = a; reverse(a.begin(), a.end());
        b += b;
        while (b.size() < 2*a.size()) b += b;
        if (b.find(a) != -1 || b.find(arev) != -1) puts("S");
        else puts("N");
    }

    return 0;
}

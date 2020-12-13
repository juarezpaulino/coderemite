/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

char A[50], B[50];

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%s %s", A, B);
        int a = 0, b = 0;
        for (int i = 0; A[i]; i++) a = (a*2) + A[i]-'0';
        for (int i = 0; B[i]; i++) b = (b*2) + B[i]-'0';
        if (__gcd(a,b)!=1) printf("Pair #%d: All you need is love!\n", t);
        else printf("Pair #%d: Love is not all you need!\n", t);
    }

    return 0;
}

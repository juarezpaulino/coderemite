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
#include <queue>

using namespace std;

char A[100], B[100];

int main() {

    while (gets(A)) {
        gets(B);
        int a = 0, b = 0;
        for (int i = 0; A[i]; i++) a += ((A[i]>='a'&&A[i]<='z')?A[i]-'a'+1 : (A[i]>='A'&&A[i]<='Z') ? A[i]-'A'+1 : 0);
        for (int i = 0; B[i]; i++) b += ((B[i]>='a'&&B[i]<='z')?B[i]-'a'+1 : (B[i]>='A'&&B[i]<='Z') ? B[i]-'A'+1 : 0);
        while (a >= 10) {
            int a2 = 0;
            while (a) { a2 += a%10; a/=10; }
            a = a2;
        }
        while (b >= 10) {
            int b2 = 0;
            while (b) { b2 += b%10; b/=10; }
            b = b2;
        }
        if (a > b) swap(a,b);
        printf("%.2lf %%\n", a*100./b);
    }

    return 0;
}

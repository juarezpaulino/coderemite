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

int F, T;
char A[100];

int main() {

    long long N;
    while (scanf("%s %d %d", A, &F, &T)!=EOF) {
        N = 0;
        for (int i = 0; A[i]; i++) {
            N *= F;
            if (A[i]>='0' && A[i]<='9') N += A[i]-'0';
            else N += A[i]-'A'+10;
        }
        string B;
        if (N == 0) B = "0";
        while (N) {
            int v = N%T;
            if (v >= 10) B = string(1,'A'+v-10) + B;
            else B = string(1,v+'0') + B;
            N/=T;
        }
        if (B.size() > 7) printf("%7s\n", "ERROR");
        else printf("%7s\n", B.c_str());
    }

    return 0;
}

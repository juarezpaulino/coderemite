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

int A, B;
char S[100];
map<char,int> M;
map<int,char> R;

int main() {

    for (int i = 0; i < 10; i++) M['0'+i] = i, R[i] = '0'+i;
    for (int i = 'A'; i <= 'F'; i++) M[i] = i-'A'+10, R[i-'A'+10] = i;
    while (scanf("%d %d %s", &A, &B, S) != EOF) {
        bool f = false;
        for (int i = 0; S[i]; i++) if (M[S[i]] >= A) { f = true; break; }
        if (f) { printf("%s is an illegal base %d number\n", S, A); continue; }
        long long v = 0;
        for (int i = 0; S[i]; i++) v = (v*A) + M[S[i]];
        string T;
        if (v==0) T = "0";
        else while (v) { T = string(1,R[v%B]) + T; v/=B; }
        printf("%s base %d = %s base %d\n", S, A, T.c_str(), B);
    }

    return 0;
}

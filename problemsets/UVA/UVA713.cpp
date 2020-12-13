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

int N;
char A[300], B[300], C[300];

int main() {

    scanf("%d", &N);
    while (N--) {
        memset(A,0,sizeof(A)); memset(B,0,sizeof(B)); memset(C,0,sizeof(C));
        scanf("%s %s", A, B);

        int NA = strlen(A), NB = strlen(B), NC = max(NA, NB);

        for (int i = 0; i < NC; i++) C[i] += ((A[i]) ? A[i]-'0' : 0) + ((B[i]) ? B[i]-'0' : 0);
        for (int i = 0; i < NC; i++) C[i+1]+=C[i]/10, C[i]=(C[i]%10)+'0';
        if (C[NC]) C[NC] += '0', NC++;
        int k = 0;
        while (C[k]=='0') k++;
        puts(C+k);
    }

    return 0;
}

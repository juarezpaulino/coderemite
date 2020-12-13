/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

using namespace std;

char S[1010101];

int main() {

    int N;
    scanf("%d",&N);
    while (N--) {
        scanf("%s", S);
        int M = strlen(S);
        if ((M==1 && S[0]!='A') || M%2==0) puts("MUTANT");
        else if (M==1 && S[0]=='A') puts("SIMPLE");
        else if (S[M-2]=='A' && S[M-1]=='B') puts("FULLY-GROWN");
        else if (S[0]=='B' && S[M-1]=='A') puts("MUTAGENIC");
        else puts("MUTANT");
    }

    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int main() {

    int K;
    char S[101], R[101];
    while (scanf("%d %s", &K, S) != EOF) {
        if (!K) break;
        int N = strlen(S);
        for (int i = 0; S[i]; i++) {
            int c = ((S[i] == '_' ? 0 : S[i]=='.' ? 27 : S[i]-'a'+1)+i)%28;
            R[(K*i)%N] = c == 0 ? '_' : c == 27 ? '.' : c-1+'a';
        }
        R[N] = 0;
        puts(R);
    }


    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

const long long MAX = 24*60*60*100LL;

int main() {

    char S[100];
    while (scanf("%s", S) != EOF) {
        long long T = 10LL*100LL*100LL*100LL *
                        (   ((S[0]-'0')*10 + (S[1]-'0')) * 60LL * 60LL * 100LL +
                            ((S[2]-'0')*10 + (S[3]-'0')) * 60LL * 100LL +
                            ((S[4]-'0')*10 + (S[5]-'0')) * 100LL +
                            ((S[6]-'0')*10 + (S[7]-'0'))
                        ) /
                        MAX;
        printf("%07lld\n", T);
    }

    return 0;
}

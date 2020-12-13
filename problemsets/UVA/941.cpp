/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

long long F[22];

string nth_permutation(string s, long long N) {
    string ret = "";
    while (N != 0) {
        int k = (int)(N/F[s.size()-1]);
        long long r = N%F[s.size()-1];
        ret += s[k];
        s.erase(k,1);
        N = r;
    }
    ret += s;
    return ret;
}

int main() {

    F[0] = F[1] = 1;
    for (int i = 2; i <= 20; i++) F[i] = F[i-1]*i;

    int T;
    scanf("%d", &T);
    while (T--) {
        char S[30];
        long long N;
        scanf("%s %lld", S, &N);
        string s = S;
        sort(s.begin(), s.end());
        printf("%s\n", nth_permutation(s, N).c_str());
    }

    return 0;
}

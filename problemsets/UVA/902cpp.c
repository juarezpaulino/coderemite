#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <cstring>

using namespace std;

char S[9010101];

int main() {

    map<string,int> M;
    int N, R = 0;
    string ret;
    while (scanf("%d %s", &N, S) != EOF) {
        for (int i = N; ; i++) {
            char c = S[i];
            S[i] = 0;
            int c = (++M[S+i-N]);
            if (c > R) R = c, ret = S+i-N;
            if (S[i]) break;
        }
        printf("%s\n", ret.c_str());
    }

    return 0;
}

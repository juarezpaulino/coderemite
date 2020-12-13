/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        map<string,int> M;
        char S[1010];
        int N = 0;
        while (gets(S)) {
            if (!*S) break;
            M[S]++;
            N++;
        }
        for (map<string,int>::iterator it = M.begin(); it != M.end(); it++)
            printf("%s %.4lf\n", it->first.c_str(), it->second * 100. / N + 1E-10);
        if (T) putchar('\n');
    }

    return 0;
}

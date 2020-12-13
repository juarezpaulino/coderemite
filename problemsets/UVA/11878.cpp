/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {

    char S[1010];
    int ret = 0;
    while (gets(S)) {
        string s = S;
        if (s.find("?") != -1) continue;
        if (s.find("+") != -1) {
            int a, b, c;
            sscanf(S, "%d+%d=%d", &a, &b, &c);
            if (a+b == c) ret++;
        }
        else {
            int a, b, c;
            sscanf(S, "%d-%d=%d", &a, &b, &c);
            if (a-b == c) ret++;
        }
    }
    printf("%d\n", ret);

    return 0;
}

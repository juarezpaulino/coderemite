/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    int ret = 0;
    while (T--) {
        char S[1010];
        int x;
        scanf("%s", S);
        if (S == string("donate")) {
            scanf("%d", &x);
            ret += x;
        }
        else printf("%d\n", ret);
    }


    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    int X[10];
    int T;

    scanf("%d", &T);
    while (T--) {
        int ret = 0;
        for (int i = 0; i < 10; i++) scanf("%d", X+i);
        for (int i = 0; i < 10; i++) for (int j = i+1; j < 10; j++) ret += (X[i] || X[j]);
        for (int i = 0; i < 10; i++) for (int j = i+1; j < 10; j++) for (int k = j+1; k < 10; k++) ret += (X[i] || X[j] || X[k]);
        if (ret & 1) puts("1");
        else puts("0");
    }

    return 0;
}

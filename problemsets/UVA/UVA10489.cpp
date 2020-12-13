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
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int T, N, B;

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {

    T = get_int();
    while (T--) {
        int ret = 0;
        N = get_int();
        B = get_int();
        for (int i = 0; i < B; i++) {
            int K, c = 1;
            K = get_int();
            for (int i = 0; i < K; i++) {
                int x;
                x = get_int();
                c = (c*x)%N;
            }
            ret = (ret+c)%N;
        }
        printf("%d\n", ret);
    }

    return 0;
}

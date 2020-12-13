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

using namespace std;

typedef long long i64;

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch==EOF) exit(0);
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {

    int N;
    while (1) {
        N = get_int();
        if (N==1) { puts("1"); continue; }
        int t = N/2+1;
        i64 l = (N+1) / 2LL * t;
        i64 ret = 6*l - 9;
        printf("%lld\n", ret);
    }

    return 0;
}

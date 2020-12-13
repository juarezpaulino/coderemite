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

map<char,int> M;

int main() {

    M['a'] = M['d'] = M['g'] = M['j'] = M['m'] = M['p'] = M['t'] = M['w'] = M[' '] = 1;
    M['b'] = M['e'] = M['h'] = M['k'] = M['n'] = M['q'] = M['u'] = M['x'] = 2;
    M['c'] = M['f'] = M['i'] = M['l'] = M['o'] = M['r'] = M['v'] = M['y'] = 3;
    M['s'] = M['z'] = 4;

    char S[1000];
    int T;
    gets(S);
    T = atoi(S);
    int t = 1;
    while (T--) {
        gets(S);
        int ret = 0;
        for (int i = 0; S[i]; i++) ret += M[S[i]];
        printf("Case #%d: %d\n", t++, ret);
    }

    return 0;
}

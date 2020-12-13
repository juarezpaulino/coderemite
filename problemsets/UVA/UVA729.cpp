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


int T;
int N, H;

string binary(int v) {
    string ret;
    for (int i = 0; i < N; i++) {
        ret = string(1,(v%2)+'0') + ret;
        v/=2;
    }
    return ret;
}

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &H);
        vector<int> RET;
        int s = (1 << H) - 1;
        while (!(s & 1 << N)) {
            RET.push_back(s);
            // do stuff with s
            int lo = s & ~(s-1); int lz = (s + lo) & ~s;
            s |= lz; s &= ~(lz-1); s |= (lz / lo / 2)-1;
        }
        for (int i = 0; i < RET.size(); i++) printf("%s\n", binary(RET[i]).c_str());
        if (T) putchar('\n');
    }

    return 0;
}

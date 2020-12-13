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

int ret[100];

int pow(int A, int p) {
    int ret = 1;
    for (int i = 0; i < p; i++) ret = (ret * A) % 10;
    return ret;
}


int main() {

    ret[0] = 0;
    for (int i = 1; i < 100; i++) ret[i] = (ret[i-1] + pow(i,i)) % 10;

    char S[500];
    while (gets(S)) {
        string s(S);
        if (s == "0") break;
        s = "0"+s;
        int N = s.size();
        int v = (s[N-2]-'0')*10 + s[N-1]-'0';
        printf("%d\n", ret[v]);
    }

    return 0;
}

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

int N;

int main() {

    while (scanf("%d", &N)) {
        if (N < 0) break;
        if (N==0) { puts("0"); continue; }
        string ret;
        while (N) { ret = string(1,(N%3)+'0') + ret; N/=3; }
        printf("%s\n", ret.c_str());
    }

    return 0;
}

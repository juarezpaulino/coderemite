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

char S[1000];

int main() {

    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", S);
        string s(S);
        if (s=="1" || s=="4" || s=="78") puts("+");
        else if (s.substr(s.size()-2)=="35") puts("-");
        else if (s[0]=='9' && s[s.size()-1]=='4') puts("*");
        else puts("?");
    }
    return 0;
}

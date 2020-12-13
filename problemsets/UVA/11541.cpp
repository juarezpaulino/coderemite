/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


int main() {

    int T;
    scanf("%d ", &T);
    int id = 1;
    while (T--) {
        char S[10101];
        gets(S);
        string s;
        for (int i = 0; S[i]; i++) {
            if (isalpha(S[i])) s += string(1,' ') + S[i] + string(1,' ');
            else s += S[i];
        }
        istringstream is(s);
        char c;
        int d;
        printf("Case %d: ", id++);
        while (is >> c >> d) for (int i = 0; i < d; i++) putchar(c);
        putchar('\n');
    }

    return 0;
}

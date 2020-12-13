/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main() {

    int T;
    char S[101010];
    scanf("%d ", &T);
    map<char,char> close;
    close[')'] = '(';
    close[']'] = '[';
    close['}'] = '{';
    while (T--) {
        gets(S);
        char *s;
        vector<char> P;
        for (s = S; *s; s++) {
            if (close.count(*s)) {
                if (!P.size() || P.back() != close[*s]) { puts("N"); break; }
                P.pop_back();
            }
            else P.push_back(*s);
        }
        if (!*s) {
            if (P.size()) puts("N");
            else puts("S");
        }
    }

    return 0;
}

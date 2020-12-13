/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <stack>
#include <sstream>

using namespace std;

char S[10101010];

int main() {

    while (gets(S)) {
        istringstream is(S);
        stack<int> U, V;
        bool ok = 1;
        int x;
        while (is >> x) {
            if (x < 0) {
                x = -x;
                U.push(x);
                V.push(0);
            }
            else {
                if (x != U.top()) { ok = 0; break; }
                U.pop();
                int v = V.top(); V.pop();
                if (v >= x) { ok = 0; break; }
                if (V.size()) { v = V.top(); V.pop(); v += x; V.push(v); }
            }
        }
        if (U.size()) ok = 0;
        if (ok) puts(":-) Matrioshka!");
        else puts(":-( Try again.");
    }

    return 0;
}

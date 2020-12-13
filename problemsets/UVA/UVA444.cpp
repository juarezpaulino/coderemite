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

set<int> V;

int main() {

    for (int i = 'a'; i <= 'z'; i++) V.insert(i);
    for (int i = 'A'; i <= 'Z'; i++) V.insert(i);
    V.insert(32); V.insert(33); V.insert(44);
    V.insert(46); V.insert(58); V.insert(59);
    V.insert(63);

    char S[1000];
    bool E;
    while (gets(S)) {
        E = (V.count(*S)) ? true : false;
        string out;
        if (E) {
            for (int i = 0; S[i]; i++) {
                char A[10];
                sprintf(A, "%d", S[i]);
                out += A;
            }
            reverse(out.begin(), out.end());
        }
        else {
            int A = 0;
            for (int i = strlen(S)-1; i >= 0; i--) {
                A = 10*A + S[i]-'0';
                if (V.count(A)) {
                    out += string(1, A);
                    A = 0;
                }
            }
        }
        printf("%s\n", out.c_str());
    }

    return 0;
}

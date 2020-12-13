/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

    int t;
    char S[30000];
    scanf("%d ", &t);
    while (t--) {
        int l = -1, P = 0, cur = 0;
        gets(S);
        string s;
        istringstream IN(S);
        while (IN >> s) {
            if (s.size() == l) cur++;
            else { l = s.size(); cur = 1; }
            P = max(P, cur);
        }
        printf("%d\n", P);
    }

    return 0;
}

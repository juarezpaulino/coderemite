/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool ispalindrome(string s) {
    int N = s.size();
    for (int i = 0; i < N/2; i++) if (s[i]!=s[N-1-i]) return false;
    return true;
}

int main() {

    char S[1010];
    while (gets(S)) {
        int N = strlen(S);
        set<string> IN;
        string s = S;
        for (int i = 0; i < N; i++) for (int j = i; j < N; j++) if (ispalindrome(s.substr(i, j-i+1))) IN.insert(s.substr(i, j-i+1));
        printf("The string '%s' contains %d palindromes.\n", S, IN.size());
    }

    return 0;
}

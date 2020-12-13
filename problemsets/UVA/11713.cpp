/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_vowel(char c) {
    c = tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}


int main() {

    int N;
    scanf("%d", &N);
    while (N--) {
        string a, b;
        cin >> a >> b;
        if (a.size() != b.size()) { puts("No"); continue; }
        bool ok = 1;
        for (int i = 0; i < a.size() && ok; i++) {
            if (is_vowel(a[i])) {
                if (!is_vowel(b[i])) ok = 0;
            }
            else if (a[i] != b[i]) ok = 0;
        }
        if (ok) puts("Yes");
        else puts("No");
    }

    return 0;
}

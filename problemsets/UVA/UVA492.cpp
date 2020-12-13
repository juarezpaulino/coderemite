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
#include <cctype>

using namespace std;

inline bool isvowel(char c) { c = toupper(c); return (c=='A'||c=='E'||c=='I'||c=='O'||c=='U');}

char W[1000000];

int main() {

    char c;
    int k = 0;
    while ((c = getchar()) != EOF) {
        if (!isalpha(c)) {
            if (k) {
                W[k] = 0;
                string s;
                if (isvowel(W[0])) s = string(W) + "ay";
                else s = string(W+1) + W[0] + string("ay");
                printf("%s", s.c_str());
                k = 0;
            }
            putchar(c);
        }
        else W[k++] = c;
    }

    return 0;
}

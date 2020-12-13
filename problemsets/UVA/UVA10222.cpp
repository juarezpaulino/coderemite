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
#include <map>

using namespace std;

map<char, char> M;

int main() {

    M['E'] = 'q'; M['I'] = 'y'; M['D'] = 'a'; M['K'] = 'h'; M['V'] = 'x'; M['.'] = 'm';
    M['R'] = 'w'; M['O'] = 'u'; M['F'] = 's'; M['L'] = 'j'; M['B'] = 'c'; M['/'] = ',';
    M['T'] = 'e'; M['P'] = 'i'; M['G'] = 'd'; M[';'] = 'k'; M['N'] = 'v'; M[' '] = ' ';
    M['Y'] = 'r'; M['['] = 'o'; M['H'] = 'f'; M['\''] = 'l'; M['M'] = 'b';
    M['U'] = 't'; M[']'] = 'p'; M['J'] = 'g'; M['C'] = 'z'; M[','] = 'n';

    char S[1000];
    while (gets(S)) {
        for (int i = 0; S[i]; i++) {
            if (!isalpha(S[i])) S[i] = M[S[i]];
            else if (isupper(S[i])) S[i] = M[S[i]];
            else S[i] = M[S[i]-'a'+'A'];
        }
        puts(S);
    }

    return 0;
}

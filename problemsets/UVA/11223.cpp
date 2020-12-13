/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {

    map<string,char> M;
    M[".-"] = 'A';
    M["-..."] = 'B';
    M["-.-."] = 'C';
    M["-.."] = 'D';
    M["."] = 'E';
    M["..-."] = 'F';
    M["--."] = 'G';
    M["...."] = 'H';
    M[".."] = 'I';
    M[".---"] = 'J';
    M["-.-"] = 'K';
    M[".-.."] = 'L';
    M["--"] = 'M';
    M["-."] = 'N';
    M["---"] = 'O';
    M[".--."] = 'P';
    M["--.-"] = 'Q';
    M[".-."] = 'R';
    M["..."] = 'S';
    M["-"] = 'T';
    M["..-"] = 'U';
    M["...-"] = 'V';
    M[".--"] = 'W';
    M["-..-"] = 'X';
    M["-.--"] = 'Y';
    M["--.."] = 'Z';
    M["-----"] = '0';
    M[".----"] = '1';
    M["..---"] = '2';
    M["...--"] = '3';
    M["....-"] = '4';
    M["....."] = '5';
    M["-...."] = '6';
    M["--..."] = '7';
    M["---.."] = '8';
    M["----."] = '9';
    M[".-.-.-"] = '.';
    M["--..--"] = ',';
    M["..--.."] = '?';
    M[".----."] = '\'';
    M["-.-.--"] = '!';
    M["-..-."] = '/';
    M["-.--."] = '(';
    M["-.--.-"] = ')';
    M[".-..."] = '&';
    M["---..."] = ':';
    M["-.-.-."] = ';';
    M["-...-"] = '=';
    M[".-.-."] = '+';
    M["-....-"] = '-';
    M["..--.-"] = '_';
    M[".-..-."] = '"';
    M[".--.-."] = '@';
    char S[3030];
    gets(S);
    int T = atoi(S);
    bool space = 0;
    for (int t = 1; t <= T; t++) {
        char w[3030];
        int nw = 0;
        gets(S);
        printf("Message #%d\n", t);
        for (int i = 0; S[i]; i++) {
            if (S[i]==' ') {
                if (nw == 0) {
                    if (space) putchar(' '), space = 0;
                    else space = 1;
                }
                else { w[nw] = 0; printf("%c", M[w]); nw = 0; space = 1; }
            }
            else w[nw++] = S[i];
        }
        if (nw) { w[nw] = 0; printf("%c", M[w]); }
        putchar('\n');
        if (t < T) putchar('\n');
    }

    return 0;
}

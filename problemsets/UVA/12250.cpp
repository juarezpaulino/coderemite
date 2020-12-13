/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main() {

    char S[100];
    int id = 1;
    while (gets(S)) {
        if (*S == '#') break;
        if (!strcmp(S, "HELLO")) printf("Case %d: ENGLISH\n", id++);
        else if (!strcmp(S, "HALLO")) printf("Case %d: GERMAN\n", id++);
        else if (!strcmp(S, "HOLA")) printf("Case %d: SPANISH\n", id++);
        else if (!strcmp(S, "BONJOUR")) printf("Case %d: FRENCH\n", id++);
        else if (!strcmp(S, "CIAO")) printf("Case %d: ITALIAN\n", id++);
        else if (!strcmp(S, "ZDRAVSTVUJTE")) printf("Case %d: RUSSIAN\n", id++);
        else printf("Case %d: UNKNOWN\n", id++);
    }


    return 0;
}

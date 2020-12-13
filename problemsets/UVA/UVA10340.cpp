/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

char S[100000], T[100000];

int main() {

    while (scanf("%s %s ", S, T) != EOF) {
        int i, j;
        for (i = j = 0; S[i] && T[j]; j++)
            if (S[i]==T[j]) i++;
        if (!S[i]) puts("Yes");
        else puts("No");
    }

    return 0;
}

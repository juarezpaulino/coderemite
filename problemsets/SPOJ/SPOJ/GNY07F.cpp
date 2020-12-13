/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
char S[155];

int main() {

    int id = 1;
    gets(S);
    sscanf(S,"%d", &T);
    while (T--) {
        gets(S);
        int d = 0, ret = 0;
        for (int i = 0; S[i]; i++) {
            if (S[i]=='[') d++;
            else if (S[i]==']') d--;
            ret = max(ret, d);
        }
        printf("%d %d\n", id, 1<<ret);
        id++;
    }

    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef long long i64;

char S1[1010], S2[1010];
int C1[256], C2[256];

int main() {

    while (gets(S1) && gets(S2)) {
        for (int i = 0; i < 256; i++) C1[i] = C2[i] = 0;
        string ret;
        for (int i = 0; S1[i]; i++) C1[S1[i]]++;
        for (int i = 0; S2[i]; i++) C2[S2[i]]++;
        for (int i = 0; i < 256; i++) ret += string(min(C1[i],C2[i]),i);
        cout << ret << endl;
    }

    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string S;
        int M;
        cin >> M >> S;
        S.erase(S.begin() + M - 1);
        printf("%d %s\n", i, S.c_str());
    }

    return 0;
}

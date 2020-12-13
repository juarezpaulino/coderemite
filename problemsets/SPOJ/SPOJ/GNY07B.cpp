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
        double M;
        cin >> M >> S;
        if (S == "kg") { M = M*2.2046; S = "lb"; }
        else if (S == "lb") { M = M*0.4536;; S = "kg"; }
        else if (S == "l") { M = M*0.2642; S = "g"; }
        else if (S == "g") { M = M*3.7854; S = "l"; }
        printf("%d %.4lf %s\n", i, M, S.c_str());
    }

    return 0;
}

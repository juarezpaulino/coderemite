/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    int k;
    string s;
    while (cin >> s) {
        if (s == ".") break;
        cin >> k;
        int N = s.size();
        string S;
        for (int i = 0; i < k; i++) S = S + s;
        for (int i = 0; i < N; i++) {
            cout << S << endl;
            rotate(S.begin(), S.begin()+1, S.end());
        }
    }

    return 0;
}

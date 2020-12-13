/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {

    int TT;
    scanf("%d ", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d: ", tt);

        string s;
        cin >> s;
        int k = s.length();
        for (int i = k-1; i > 0; i--)
            if (s[i-1] > s[i])
                k = i, s[i-1]--;
        string ret = s.substr(0,k) + string(s.length()-k, '9');
        if (ret[0]=='0') ret = string(s.length()-1, '9');
        cout << ret << endl;
    }
    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

char H[10101];
char S[1010];
int s = 0;
map<string, char> mapa;

string getCode(int t) {
    string ret = "";
    for (int i = 0; i < t; i++) {
        if (!S[s]) { scanf("%s", S); s = 0; }
        ret += S[s++];
    }
    return ret;
}

int main() {

    while (gets(H)) {
        mapa.clear();
        mapa["0"] = H[0];
        int p = 1, l = 2;
        while (H[p]) {
            int last = (1<<l)-1;
            for (int i = 0; i < last && H[p]; i++) {
                string c = "";
                int v = i;
                for (int j = 0; j < l; j++) { c += (v%2)+'0'; v /= 2; }
                reverse(c.begin(), c.end());
                mapa[c] = H[p++];
            }
            l++;
        }
        string ret = "";
        while (1) {
            string a = getCode(3);
            if (a == "000") break;
            int l = 0;
            for (int i = 0; i < 3; i++) l = l*2 + a[i]-'0';
            while (1) {
                string c = getCode(l);
                if (c == string(l, '1')) break;
                ret += mapa[c];
            }
        }
        printf("%s\n", ret.c_str());
        gets(H);
    }

    return 0;
}

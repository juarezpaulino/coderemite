/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>

using namespace std;

int main() {

    int L;
    while (scanf("%d", &L) != EOF && L) {
        string ret = "+x";
        for (int i = 0; i < L-1; i++) {
            char S[10];
            scanf("%s", S);
            string s = S;
            int g;
            if (s == "No") continue;
            g = (s[0]=='+') ? 1 : 0;
            if (s[1]=='y') {
                if (ret[1]=='z') continue;
                else if (ret[1]=='x') {
                    g ^= (ret[0]=='+') ? 1 : 0;
                    ret = g ? "-y" : "+y";
                }
                else if (ret[1]=='y') {
                    g ^= (ret[0]=='+') ? 1 : 0;
                    ret = g ? "+x" : "-x";
                }
            }
            if (s[1]=='z') {
                if (ret[1]=='y') continue;
                else if (ret[1]=='x') {
                    g ^= (ret[0]=='+') ? 1 : 0;
                    ret = g ? "-z" : "+z";
                }
                else if (ret[1]=='z') {
                    g ^= (ret[0]=='+') ? 1 : 0;
                    ret = g ? "+x" : "-x";
                }
            }
        }
        puts(ret.c_str());
    }

    return 0;
}

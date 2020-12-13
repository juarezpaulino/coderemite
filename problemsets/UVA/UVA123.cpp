/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

set<string> G;
char S[1000];
string T[300];
set<string> K;

int main() {

    while (gets(S)) {
        if (!strcmp(S,"::")) break;
        G.insert(S);
    }
    int N = 0;
    while (gets(S)) {
        transform(S, S+strlen(S), S, ::tolower);
        T[N++] = S;
        istringstream is(S);
        while (is >> S) if (!G.count(S)) K.insert(S);
    }
    for (set<string>::iterator it = K.begin(); it != K.end(); it++) {
        string w = *it;
        int p = 0;
        for (int i = 0; i < N; i++) {
            while ((p = T[i].find(w,p)) != -1) {
                int l = p+w.size();
                if ((p==0 || !isalpha(T[i][p-1])) && (l >= T[i].size() || !isalpha(T[i][p+w.size()]))) {
                    string s = T[i];
                    string W = w;
                    transform(W.begin(), W.end(), W.begin(), ::toupper);
                    s.replace(p,w.size(),W);
                    printf("%s\n", s.c_str());
                }
                p += w.size();
            }
        }
    }

    return 0;
}

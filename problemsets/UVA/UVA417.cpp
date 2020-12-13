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

char S[20];
map<string, int> M;

int main() {

    int K = 1;
    queue<string> Q;
    for (int i = 'a'; i <= 'z'; i++) Q.push(string(1,i));
    while (!Q.empty()) {
        string u = Q.front(); Q.pop();
        M[u] = K++;
        if (u.size() > 5) break;
        for (int i = u[u.size()-1]+1; i <= 'z'; i++) Q.push(u+string(1,i));
    }

    while (gets(S)) {
        bool f = false;;
        for (int i = 1; S[i]; i++) if (S[i] <= S[i-1]) f = true;
        if (f) puts("0");
        else printf("%d\n", M[S]);
    }

    return 0;
}

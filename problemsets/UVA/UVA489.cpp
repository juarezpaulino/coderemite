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

char W[500];
char G[500];

int main() {

    int N;
    while (scanf("%d", &N)) {
        if (N==-1) break;
        printf("Round %d\n", N);
        scanf("%s %s", W, G);
        set<char> IN, C, OUT;
        for (int i = 0; W[i]; i++) IN.insert(W[i]);
        C = IN;
        int k = 0;
        for (int i = 0; C.size() && G[i] && k < 7; i++) {
            if (IN.count(G[i])) {
                if (C.count(G[i])) C.erase(G[i]);
            }
            else if (!OUT.count(G[i])) {
                k++; OUT.insert(G[i]);
            }
        }
        if (k == 7) puts("You lose.");
        else if (C.size()) puts("You chickened out.");
        else puts("You win.");
    }

    return 0;
}

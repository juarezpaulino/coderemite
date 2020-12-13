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

char S[100000];

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        vector<int> P;
        vector<string> V, RET;
        gets(S);
        {istringstream is(S);
        int x;
        while (is >> x) P.push_back(x);
        }
        gets(S);
        {istringstream is(S);
        while (is >> S) V.push_back(S);
        }
        RET.resize(V.size());
        for (int i = 0; i < V.size(); i++) RET[P[i]-1] = V[i];
        for (int i = 0; i < RET.size(); i++) printf("%s\n", RET[i].c_str());
        if (T) putchar('\n');
        scanf(" ");
    }

    return 0;
}

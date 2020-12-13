/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        vector<string> ret;
        int v = -1;
        printf("Case #%d:\n", t);
        for (int i = 0; i < 10; i++) {
            char S[505];
            int x;
            scanf("%s %d", S, &x);
            if (v == -1 || x > v) ret.clear(), ret.push_back(S), v = x;
            else if (x == v) ret.push_back(S);
        }
        for (int i = 0; i < ret.size(); i++) printf("%s\n", ret[i].c_str());
    }

    return 0;
}

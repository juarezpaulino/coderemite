/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

map<int,int> M;

int dfs(int p) {
    int v;
    scanf("%d", &v); if (v != -1) { M[p-1] += v; dfs(p-1); }
    scanf("%d", &v); if (v != -1) { M[p+1] += v; dfs(p+1); }
}

int main() {

    int v, id = 1;
    while (scanf("%d", &v) != EOF) {
        if (v == -1) break;
        M.clear();
        M[0] = v;
        dfs(0);
        printf("Case %d:\n", id++);
        bool f = 1;
        for (map<int,int>::iterator it = M.begin(); it != M.end(); it++) {
            if (!f) putchar(' ');
            f = 0;
            printf("%d", it->second);
        }
        putchar('\n');
        putchar('\n');
    }

    return 0;
}

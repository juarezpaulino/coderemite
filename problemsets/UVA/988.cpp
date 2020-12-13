/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int N;
vector<int> DP;
vector<vector<int> > adj;

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch==EOF) return ch;
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}

int go(int k) {
    int &ret = DP[k];
    if (ret != -1) return ret;
    if (adj[k].size()==0) return ret = 1;
    ret = 0;
    for (int i = 0; i < adj[k].size(); i++) {
        int v = adj[k][i];
        ret += go(v);
    }
    return ret;
}


int main() {

    bool f = 1;
    while ((N = get_int()) != EOF) {
        adj = vector<vector<int> >(N, vector<int>());
        DP = vector<int>(N,-1);
        for (int i = 0; i < N; i++) {
            int m = get_int();
            while (m--) {
                int v = get_int();
                adj[i].push_back(v);
            }
        }
        int ret = go(0);
        if (!f) putchar('\n');
        f = 0;
        printf("%d\n", ret);
    }

    return 0;
}

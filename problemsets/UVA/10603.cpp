/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct node {
    int v[4];
    bool operator<(const node &B) const {
        return v[3] > B.v[3];
    }
};

int vis[202][202][202], D[202][202][202], id = 1;
int v[4];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", v, v+1, v+2, v+3);
        priority_queue<node> q;
        q.push((node){0,0,v[2],D[0][0][v[2]]=0});
        vis[0][0][v[2]]=id;
        int mind = (v[2] <= v[3]) ? v[2] : 0;
        int ret = 0;
        while (!q.empty()) {
            node u = q.top(); q.pop();
            if (u.v[0]==v[3]||u.v[1]==v[3]||u.v[2]==v[3]) {
                ret = u.v[3];
                mind = v[3];
                break;
            }
            if (u.v[3] != D[u.v[0]][u.v[1]][u.v[2]]) continue;
            for (int i = 0; i < 3; i++) {
                if (u.v[i] < v[3] && u.v[i] > mind) {
                    mind = u.v[i]; ret = u.v[3];
                }
            }
            for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (i != j) {
                if (u.v[j] < v[j]) {
                    node B = u;
                    int c = min(u.v[i], v[j]-u.v[j]);
                    B.v[i]-=c; B.v[j]+=c; B.v[3]+=c;
                    if (vis[B.v[0]][B.v[1]][B.v[2]]!=id || B.v[3] < D[B.v[0]][B.v[1]][B.v[2]])
                        q.push(B), D[B.v[0]][B.v[1]][B.v[2]] = B.v[3], vis[B.v[0]][B.v[1]][B.v[2]]=id;
                }
            }
        }
        printf("%d %d\n", ret, mind);
        id++;
    }

    return 0;
}

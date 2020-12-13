/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

int vis[55][55], D[55][55], id = 1;
char M[55][55], K[55][55];

const int MAX_SET = 110;

int up[MAX_SET];

void init(int n) { for (int i = 0; i < n; i++) up[i] = -1; }

int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }

bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int main() {

    int T;
    int R, C;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d ", &C, &R);
        memset(M,0,sizeof(M));
        vector<pair<int,int> > V;
        for (int i = 0; i < R; i++) {
            gets(M[i]);
            for (int j = 0; j < C; j++)
                if (M[i][j]=='A'||M[i][j]=='S') {
                    K[i][j] = V.size();
                    V.push_back(make_pair(i,j));
                }
        }

        int N = V.size();
        priority_queue<pair<int,pii> > q;
        for (int i = 0; i < N; i++) {
            int y = V[i].first, x = V[i].second;
            queue<int> qx, qy;
            qx.push(x); qy.push(y);
            D[y][x] = 0;
            vis[y][x] = id;
            while (!qx.empty()) {
                y = qy.front(); x = qx.front();
                qy.pop(); qx.pop();
                if (M[y][x]=='A'||M[y][x]=='S') {
                    if (i != K[y][x])
                        q.push(make_pair(-D[y][x], make_pair(i,K[y][x])));
                }
                for (int j = 0; j < 4; j++) {
                    int ny = y+dy[j], nx = x+dx[j];
                    if (ny < 0 || nx < 0 || ny >= R || nx >= C || vis[ny][nx]==id || M[ny][nx]=='#')
                        continue;
                    qx.push(nx); qy.push(ny);
                    D[ny][nx] = D[y][x]+1;
                    vis[ny][nx] = id;
                }
            }
            id++;
        }

        int k = 0;
        int ret = 0;
        init(N);
        while (!q.empty() && k < N-1) {
            int u = q.top().second.first,
                v = q.top().second.second,
                w = -q.top().first;
            q.pop();
            if (join(u,v)) ret += w, k++;
        }
        printf("%d\n", ret);
    }

    return 0;
}

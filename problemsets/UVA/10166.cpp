/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int marc[250000], id;

int C;
map<string,int> mapC;
int mapNo[110][2500], rmapNo[250000][2];
int D[250000];

vector<vector<int> > adj;
vector<int> noList[110];

char S[101010];

int s, e;

int go(int u) {
    int &ret = D[u];
    if (ret != -1) return ret;
    if (rmapNo[u][0]==e) return ret = rmapNo[u][1];
    ret = 1<<30;
    for (int i = 0; i < adj[u].size(); i++) ret = min(ret, go(adj[u][i]));
    return ret;
}

int main() {

    while (scanf("%d", &C) && C) {
        id++;
        mapC.clear();
        adj.clear();
        for (int i = 0; i < C; i++) {
            scanf("%s", S);
            mapC[S] = i;
            noList[i].clear();
        }
        int T; scanf("%d", &T);
        for (int k = 0; k < T; k++) {
            int t; scanf("%d", &t);
            vector<pii> no;
            for (int i = 0; i < t; i++) {
                int h; scanf("%d %s", &h, S);
                int c = mapC[S], v;
                if (marc[c*2500+h]==id) v = mapNo[c][h];
                else {
                    v = adj.size();
                    adj.push_back(vector<int>());
                    marc[c*2500+h] = id;
                    mapNo[c][h] = v;
                    rmapNo[v][0] = c, rmapNo[v][1] = h;
                    noList[c].push_back(v);
                }
                no.push_back(pii(h,v));
            }
            if (no.size() < 2) continue;
            sort(no.begin(), no.end());
            int u = no[0].second;
            for (int i = 1; i < no.size(); i++) {
                int v = no[i].second;
                adj[u].push_back(v);
                u = v;
            }
        }

        int sTime;
        scanf("%d", &sTime);
        scanf("%s", S); s = mapC[S];
        scanf("%s", S); e = mapC[S];

        // Connect trains from same city.
        for (int k = 0; k < C; k++) {
            vector<pii> no;
            for (int i = 0; i < noList[k].size(); i++) {
                int u = noList[k][i], t = rmapNo[u][1];
                no.push_back(pii(t,u));
            }
            if (no.size() < 2) continue;
            sort(no.begin(), no.end());
            int u = no[0].second;
            for (int i = 1; i < no.size(); i++) {
                int v = no[i].second;
                adj[u].push_back(v);
                u = v;
            }
        }

        int retS = -1, retE = 1<<29;
        for (int i = 0; i < adj.size(); i++) D[i] = -1;
        for (int i = 0; i < noList[s].size(); i++) {
            int u = noList[s][i];
            if (rmapNo[u][1] >= sTime) {
                int ret = go(u);
                if (ret < retE || (ret==retE && rmapNo[u][1] > retS))
                    retE = ret, retS = rmapNo[u][1];
            }
        }

        if (retS == -1) puts("No connection");
        else printf("%04d %04d\n", retS, retE);
    }

    return 0;
}

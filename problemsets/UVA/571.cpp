/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int CA, CB, N;
char V[1010][1010];
pair<int,int> P[1010][1010];
string RET[1010][1010];

int main() {

    while (scanf("%d %d %d", &CA, &CB, &N) != EOF) {
        memset(V,0,sizeof(V));
        queue<pair<int, int> > q;
        q.push(make_pair(0,0));
        P[0][0] = make_pair(-1,-1); V[0][0] = 1;
        pair<int,int> u;
        while (!q.empty()) {
            u = q.front(); q.pop();
            if (u.second == N) break;
            if (!V[CA][u.second]) {
                RET[CA][u.second] = "fill A";
                V[CA][u.second] = 1;
                P[CA][u.second] = make_pair(u.first, u.second);
                q.push(make_pair(CA, u.second));
            }
            if (!V[u.first][CB]) {
                RET[u.first][CB] = "fill B";
                V[u.first][CB] = 1;
                P[u.first][CB] = make_pair(u.first, u.second);
                q.push(make_pair(u.first, CB));
            }
            if (!V[0][u.second]) {
                RET[0][u.second] = "empty A";
                V[0][u.second] = 1;
                P[0][u.second] = make_pair(u.first, u.second);
                q.push(make_pair(0, u.second));
            }
            if (!V[u.first][0]) {
                RET[u.first][0] = "empty B";
                V[u.first][0] = 1;
                P[u.first][0] = make_pair(u.first, u.second);
                q.push(make_pair(u.first, 0));
            }
            int c;
            c = min(CB-u.second, u.first);
            if (!V[u.first-c][u.second+c]) {
                RET[u.first-c][u.second+c] = "pour A B";
                V[u.first-c][u.second+c] = 1;
                P[u.first-c][u.second+c] = make_pair(u.first, u.second);
                q.push(make_pair(u.first-c,u.second+c));
            }
            c = min(CA-u.first, u.second);
            if (!V[u.first+c][u.second-c]) {
                RET[u.first+c][u.second-c] = "pour B A";
                V[u.first+c][u.second-c] = 1;
                P[u.first+c][u.second-c] = make_pair(u.first, u.second);
                q.push(make_pair(u.first+c,u.second-c));
            }
        }
        vector<string> ret;
        ret.push_back("success");
        while (P[u.first][u.second].first != -1) {
            ret.push_back(RET[u.first][u.second]);
            u = P[u.first][u.second];
        }
        reverse(ret.begin(), ret.end());
        for (int i = 0; i < ret.size(); i++) printf("%s\n", ret[i].c_str());
    }

    return 0;
}

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
#include <numeric>
#include <stack>

using namespace std;

set<pair<int,int> > VIS;
int N;
char S[1000010];
int sx, sy, tx, ty;
bool reach;
string ret;

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}

void go(int x, int y) {
    char S[20];
    sprintf(S, "(%d,%d) ", x, y);
    ret += S;
    VIS.insert(make_pair(x,y));
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
        if (ny==ty && nx==tx) {
            sprintf(S, "(%d,%d) ", nx, ny);
            ret += S;
            reach = 1;
        }
    }
    if (reach) return;
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
        if (VIS.count(make_pair(nx,ny))) continue;
        go(nx, ny);
        if (reach) return;
        ret += S;
    }
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        VIS.clear();
        scanf("%d ", &N);
        gets(S);
        vector<string> is = tokenize(S, "(), ");
        sx = atoi(is[0].c_str());
        sy = atoi(is[1].c_str());
        tx = atoi(is[2].c_str());
        ty = atoi(is[3].c_str());
        int x, y;
        for (int i = 4; i < is.size(); i+=2) {
            x = atoi(is[i].c_str());
            y = atoi(is[i+1].c_str());
            VIS.insert(make_pair(x,y));
        }
        reach = false;
        ret = "";
        go(sx,sy);
        ret = ret.substr(0,ret.size()-1);
        printf("%s\n", ret.c_str());
    }

    return 0;
}

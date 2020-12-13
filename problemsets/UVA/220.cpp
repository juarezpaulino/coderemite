/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

typedef pair<int,int> PII;

char MAPA[10][10];

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool go(int r, int c, int d, char cur, bool change, bool ok) {
    if (r < 0 || r >= 8 || c < 0 || c >= 8 || MAPA[r][c]==2) return false;

    bool ret = 0;
    if (MAPA[r][c] == 1-cur) {
        ret = go(r+dy[d], c+dx[d], d, cur, change, 1);
        if (ret && change) MAPA[r][c] = cur;
    }
    else ret = ok;
    return ret;
}

bool check(int r, int c, char cur, bool change) {
        bool ok = 0;
        for (int d = 0; d < 8; d++) if (go(r+dy[d], c+dx[d], d, cur, change, 0)) {
            if (!change) return true;
            ok = 1;
            MAPA[r][c] = cur;
        }

        return ok;
}

vector<PII> moves(char cur) {
    vector<PII> ret;
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) if (MAPA[i][j] == 2) {
        if (check(i, j, cur, 0)) ret.push_back(PII(i+1,j+1));
    }
    return ret;
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        char cur;
        for (int i = 0; i < 8; i++) scanf("%s ", MAPA[i]);
        for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) MAPA[i][j] = (MAPA[i][j]=='W') ? 0 : (MAPA[i][j]=='B') ? 1 : 2;
        scanf("%c ", &cur);
        cur = (cur == 'W') ? 0 : 1;
        while (1) {
            char c;
            scanf("%c", &c);
            if (c == 'L') {
                vector<PII> M = moves(cur);
                if (M.size() == 0) puts("No legal move.");
                else {
                    for (int i = 0; i < M.size(); i++) {
                        if (i) putchar(' ');
                        printf("(%d,%d)", M[i].first, M[i].second);
                    }
                    putchar('\n');
                }
            }
            else if (c == 'M') {
                char r, c;
                scanf("%c%c", &r, &c);
                if (!check(r-'0'-1, c-'0'-1, cur, 1)) {
                    cur = 1-cur;
                    check(r-'0'-1, c-'0'-1, cur, 1);
                }
                int w = 0, b = 0;
                for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) if (MAPA[i][j]==0) w++; else if (MAPA[i][j]==1) b++;
                printf("Black - %2d White - %2d\n", b, w);
                cur = 1-cur;
            }
            else {
                for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) MAPA[i][j]=(MAPA[i][j]==0)?'W':(MAPA[i][j]==1)?'B':'-';
                for (int i = 0; i < 8; i++) printf("%s\n", MAPA[i]);
                break;
            }
            scanf(" ");
        }
        if (T) putchar('\n');
    }

    return 0;
}

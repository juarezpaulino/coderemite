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

char rank[] = "*A23456789TJQK";
char suit[] = "CDHS";

struct card {
    int r, s;
    int read() {
        char c[2];
        if (scanf(" %c%c", &c[0], &c[1]) == EOF) exit(0);
        if (c[0]=='#' || c[1]=='#') exit(0);
        for (r = 0; rank[r] != c[0]; r++);
        for (s = 0; suit[s] != c[1]; s++);
        return 1;
    }
    void print() { printf("%c%c", rank[r], suit[s]); }
};

card P[15][4];
int V[15];

int main() {

    while (1) {
        for (int j = 0; j < 4; j++) for (int i = 13; i >= 1; i--) P[i][j].read();
        for (int i = 1; i <= 13; i++) V[i] = 0;
        int y = 13, x = 0, ret = 1, r;
        V[y]++;
        while (V[(r = P[y][x].r)] < 4) {
            y = r; x = V[r];
            V[r]++;
            ret++;
        }
        printf("%02d,", ret); P[y][x].print(); putchar('\n');
    }

    return 0;
}

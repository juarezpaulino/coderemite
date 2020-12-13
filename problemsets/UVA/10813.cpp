/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>

using namespace std;


int main() {

    int N;
    int x;
    scanf("%d", &N);
    for (int t = 1; t <= N; t++) {
        map<int,pair<int,int> > mapa;
        int row[5] = {0};
        int col[5] = {0};
        int d1 = 1, d2 = 1;
        row[2] = 1; col[2] = 1;
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) continue;
            scanf("%d", &x);
            mapa[x] = make_pair(i,j);
        }
        bool done = 0;
        for (int i = 0; i < 75; i++) {
            scanf("%d", &x);
            if (done) continue;
            if (mapa.count(x)) {
                int r = mapa[x].first, c = mapa[x].second;
                row[r]++;
                col[c]++;
                if (r == c) d1++;
                if (r == 4-c) d2++;
                if (row[r] == 5 || col[c] == 5 || d1 == 5 || d2 == 5) {
                    printf("BINGO after %d numbers announced\n", i+1);
                    done = 1;
                }
            }
        }
    }

}

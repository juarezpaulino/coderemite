/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int points[] = { 1, 3, 5, 7, 9, 9 };
int meta[] = { 112, 102, 82, 72 };

struct card {
    int rank;
    int read() {
        char c[10];
        string C;
        scanf(" %s", c);
        C = c;
        if (C == "fool") { rank = 5; return 1; }
        else if (C == "one") rank = 5;
        else if (C == "twenty-one") rank = 5;
        else if (C == "king") rank = 4;
        else if (C == "queen") rank = 3;
        else if (C == "knight") rank = 2;
        else if (C == "jack") rank = 1;
        else rank = 0;
        scanf(" %*s %*s");
        return 1;
    }
};


int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int M;
        scanf("%d", &M);
        int oudlers = 0, v = 0;
        while (M--) {
            card c;
            c.read();
            if (c.rank == 5) oudlers++;
            v += points[c.rank];
        }

        M = meta[oudlers];

        printf("Hand #%d\n", t);
        if (v >= M) printf("Game won by %d point(s).\n", (v-M) / 2);
        else printf("Game lost by %d point(s).\n", (M-v) / 2);

        if (t != T) putchar('\n');
    }

    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

const char* rank_names = "**23456789TJQKA";
const char* suit_names = "CDHS";

struct card {
    int rank, suit;
    int read() {
        char ch[2];
        if (scanf(" %c%c", &ch[0], &ch[1]) == EOF || ch[0]=='#') return 0;
        for (rank = 0; rank_names[rank] != ch[1]; rank++);
        for (suit = 0; suit_names[suit] != ch[0]; suit++);
        return 1;
    }
    void print() { printf("%c%c", rank_names[rank], suit_names[suit]); }
};


int main() {

    while (1) {
        deque<card> A[2];
        card c;
        int p = 0;
        for (int i = 0; i < 52; i++) {
            if (c.read() == 0) return 0;
            A[p].push_back(c);
            p = 1-p;
        }
        deque<card> S;
        int w = -1, n = 1;
        while (1) {
            if (A[p].size() == 0) { w = 1-p; break; }
            c = A[p].back(); A[p].pop_back();
            S.push_back(c);
            if (c.rank >= 11) {
                if (c.rank == 11) n = 1;
                if (c.rank == 12) n = 2;
                if (c.rank == 13) n = 3;
                if (c.rank == 14) n = 4;
                w = p;
                p = 1-p;
                continue;
            }
            if (--n == 0) {
                if (w != -1) {
                    while (!S.empty()) {
                        A[w].push_front(S.front());
                        S.pop_front();
                    }
                }
                p = 1-p;
                w = -1;
                n = 1;
            }
        }
        printf("%d%3d\n", 2-w, A[w].size());
    }

    return 0;
}

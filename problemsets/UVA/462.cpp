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
        if (scanf(" %c%c", &ch[0], &ch[1]) == EOF) return 0;
        for (rank = 0; rank_names[rank] != ch[0]; rank++);
        for (suit = 0; suit_names[suit] != ch[1]; suit++);
        return 1;
    }
    void print() { printf("%c%c", rank_names[rank], suit_names[suit]); }
};


int main() {

    while (1) {
        card A[13];
        for (int i = 0; i < 13; i++)
            if (!A[i].read()) return 0;
        // Points for cards and check stopped
        int u = 0, v = 0;
        int cdhs[4] = {0};
        int stopped[4] = {0};
        for (int i = 0; i < 13; i++) {
            if (A[i].rank == 14) {
                u += 4;
                stopped[A[i].suit] = 1;
            }
            if (A[i].rank == 13) {
                u += 3;
                int c = 0;
                for (int j = 0; j < 13; j++) if (i != j && A[i].suit == A[j].suit) c++;
                if (c <= 0) u--;
                if (c >= 1) stopped[A[i].suit] = 1;
            }
            if (A[i].rank == 12) {
                u += 2;
                int c = 0;
                for (int j = 0; j < 13; j++) if (i != j && A[i].suit == A[j].suit) c++;
                if (c <= 1) u--;
                if (c >= 2) stopped[A[i].suit] = 1;
            }
            if (A[i].rank == 11) {
                u += 1;
                int c = 0;
                for (int j = 0; j < 13; j++) if (i != j && A[i].suit == A[j].suit) c++;
                if (c <= 2) u--;
            }
            cdhs[A[i].suit]++;
        }
        int trump = 0;
        // Points for suits
        for (int i = 0; i < 4; i++) {
            if (cdhs[i]==2) v++;
            if (cdhs[i]==1) v+=2;
            if (cdhs[i]==0) v+=2;
            if (stopped[i]) trump++;
        }
        if (u+v < 14) puts("PASS");
        else if (u >= 16 && trump == 4) puts("BID NO-TRUMP");
        else {
            int ret = 0;
            for (int i = 1; i < 4; i++) if (cdhs[i] >= cdhs[ret]) ret = i;
            printf("BID %c\n", suit_names[ret]);
        }
    }

    return 0;
}

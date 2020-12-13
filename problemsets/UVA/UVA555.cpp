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

using namespace std;

inline char get_token() {
    char c;
    while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
    return c;
}


const char* rank_names = "**23456789TJQKA";
const char* suit_names = "CDSH";
const char* player = "SWNE";

struct card {
    int rank, suit;
    int read() {
        char ch[2];
        ch[0] = get_token(); ch[1] = get_token();
        for (rank = 0; rank_names[rank] != ch[1]; rank++);
        for (suit = 0; suit_names[suit] != ch[0]; suit++);
        return 1;
    }
    void print() { printf(" %c%c", suit_names[suit], rank_names[rank]); }
};

bool comp(const card A, const card B) {
    if (A.suit != B.suit) return A.suit < B.suit;
    return A.rank < B.rank;
}

card C[4][13];
char D;


int main() {

    while ((D = get_token()) != EOF) {
        if (D == '#') break;
        int p;
        for (p = 0; player[p] != D; p++); p = (p+1)%4;
        for (int i = 0; i < 52; i++, p = (p+1)%4) C[p][i>>2].read();
        sort(&C[0][0], &C[1][0], comp);
        sort(&C[1][0], &C[2][0], comp);
        sort(&C[2][0], &C[3][0], comp);
        sort(&C[3][0], &C[4][0], comp);
        for (int k = 0; k < 4; k++) {
            printf("%c:", player[k]);
            for (int i = 0; i < 13; i++) C[k][i].print();
            putchar('\n');
        }
    }

    return 0;
}

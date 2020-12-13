/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

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

struct freq_lt {
    int* freq;
    freq_lt(int* freq): freq(freq) {}
    bool operator ()(const card A, const card B) const {
        if (int t = freq[A.rank] - freq[B.rank]) return t > 0;
        else return A.rank > B.rank;
    }
};

struct hand {
    card C[5];
    int type() {
        int freq[15]; memset(freq, 0, sizeof(freq));
        sort(C, C+5, freq_lt(freq));
        bool flush = true, straight = true;
        for (int i = 0; i < 5; i++) {
            if (i && C[i].suit != C[i-1].suit) flush = false;
            if (i && !(C[i].rank == 5 && C[i-1].rank == 14) && \
            C[i].rank != C[i-1].rank - 1) straight = false;
            freq[C[i].rank]++;
        }
        sort(C, C+5, freq_lt(freq));
        int kind[5]; memset(kind, 0, sizeof(kind));
        for (int i = 2; i <= 14; i++) kind[freq[i]]++;
        if (straight && flush) return 8;
        else if (kind[4]) return 7;
        else if (kind[3] && kind[2]) return 6;
        else if (flush) return 5;
        else if (straight) return 4;
        else if (kind[3]) return 3;
        else return kind[2];
    }
    bool operator <(hand H) {
        if (int t = type() - H.type()) return t < 0;
        for (int i = 0; i < 5; i++)
            if (int t = C[i].rank - H.C[i].rank) return t < 0;
        return false;
    }
};


int main() {

    card C[10];
    while (1) {
        for (int i = 0; i < 10; i++) if (!C[i].read()) return 0;
        bool first = 1;
        hand H, ret;
        for (int k = 0; k < (1<<5); k++) {
            int n = 0;
            for (int j = 0; j < 5; j++) if (k & (1<<j)) H.C[n++] = C[j];
            for (int j = 5; n < 5 && j < 10; j++) H.C[n++] = C[j];
            if (first || ret < H) ret = H, first = 0;
        }
        printf("Hand:");
        for (int i = 0; i < 5; i++) putchar(' '), C[i].print();
        printf(" Deck:");
        for (int i = 5; i < 10; i++) putchar(' '), C[i].print();
        printf(" Best hand: ");
        switch (ret.type()) {
            case 8: puts("straight-flush"); break;
            case 7: puts("four-of-a-kind"); break;
            case 6: puts("full-house"); break;
            case 5: puts("flush"); break;
            case 4: puts("straight"); break;
            case 3: puts("three-of-a-kind"); break;
            case 2: puts("two-pairs"); break;
            case 1: puts("one-pair"); break;
            case 0: puts("highest-card");
        }
    }

    return 0;
}

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

const char* rank_names = "*A23456789TJQK";
const char* suit_names = "CDHS";

struct card {
    int rank, suit;
    card() : rank(0), suit(0) {}
    int read() {
        char ch[2];
        if (scanf(" %c%c", &ch[0], &ch[1]) == EOF) return 0;
        if (ch[0]=='#') exit(0);
        for (rank = 0; rank_names[rank] != ch[0]; rank++);
        for (suit = 0; suit_names[suit] != ch[1]; suit++);
        return 1;
    }
    void print() { printf("%c%c", rank_names[rank], suit_names[suit]); }
};

vector<vector<card> >C;

bool match(int k) {
    if (k > 2 && ((C[k].back().rank==C[k-3].back().rank) || (C[k].back().suit==C[k-3].back().suit))) {
        card l = C[k].back();
        C[k-3].push_back(l);
        C[k].pop_back();
        if (C[k].size()==0) C.erase(C.begin() + k);
        return 1;
    }
    if (k > 0 && ((C[k].back().rank==C[k-1].back().rank) || (C[k].back().suit==C[k-1].back().suit))) {
        card l = C[k].back();
        C[k-1].push_back(l);
        C[k].pop_back();
        if (C[k].size()==0) C.erase(C.begin() + k);
        return 1;
    }
    return 0;
}


int main() {

    while (1) {
        C.clear();
        for (int k = 0; k < 52; k++) {
            C.push_back(vector<card>(1, card()));
            C.back().back().read();
            bool change = match(C.size()-1);
            while (change) {
                change = 0;
                for (int i = 1; i < C.size(); i++)
                    if (match(i)) {
                        change = 1;
                        break;
                    }
            }
        }
        printf("%d %s remaining:", C.size(), C.size()==1 ? "pile" : "piles");
        for (int i = 0; i < C.size(); i++) {
            printf(" %d", C[i].size());
        }
        putchar('\n');
    }

    return 0;
}

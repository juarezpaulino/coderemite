/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <set>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    char order[12][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    set<string> in[12];
    for (int i = 0; i < 12; i++) {
        int p = i;
        for (int k = 0; k < 7; k++) {
            in[i].insert(order[p]);
            if (k == 2) p = (p+1)%12;
            else p = (p+2)%12;
        }
    }

    char S[1010];
    while (gets(S)) {
        if (S == string("END")) break;

        istringstream is(S);
        string s;
        vector<string> input;
        while (is >> s) input.push_back(s);

        bool first = 1;
        for (int i = 0; i < 12; i++) {
            bool ok = 1;

            for (int j = 0; j < input.size(); j++)
                if (!in[i].count(input[j])) { ok = 0; break; }

            if (ok) {
                if (first) { printf("%s", order[i]); first = 0; }
                else printf(" %s", order[i]);
            }
        }
        putchar('\n');
    }

    return 0;
}

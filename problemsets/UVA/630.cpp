/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <string>
#include <map>


using namespace std;

struct state {
    int v[26];
    state() { for (int i = 0; i < 26; i++) v[i] = 0; }
    bool operator<(const state &B) const {
        for (int i = 0; i < 26; i++)
            if (v[i] != B.v[i]) return v[i] < B.v[i];
        return false;
    }
};

map<state, vector<string> > D;


int main() {

    int M, N;
    char S[1010];
    scanf("%d ", &M);
    for (int m = 0; m < M; m++) {
        scanf("%d ", &N);
        D.clear();
        while (N--) {
            scanf("%s", S);
            state u;
            for (int i = 0; S[i]; i++) u.v[S[i]-'a']++;
            D[u].push_back(S);
        }
        while (1) {
            scanf("%s ", S);
            if (S == string("END")) break;
            state u;
            for (int i = 0; S[i]; i++) u.v[S[i]-'a']++;
            vector<string> ret;
            if (D.count(u)) ret = D[u];

            printf("Anagrams for: %s\n", S);
            if (ret.size() == 0) { printf("No anagrams for: %s\n", S); continue; }

            int id = 1;
            for (int i = 0; i < ret.size(); i++) {
                printf("%3d) %s\n", id++, ret[i].c_str());
            }
        }

        if (m < M-1) putchar('\n');
    }

    return 0;
}

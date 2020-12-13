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

char S[100], T[100];

map<string, int> MAPA;
map<int, int> C;
vector<string> R, RET;

int main() {

    while (scanf("%s", S)) {
        if (*S=='#') break;

        int N = strlen(S);
        transform(S, S+N, T, ::tolower);
        *(T+N) = 0;
        sort(T, T+N);
        if (!MAPA.count(T)) {
            int k = MAPA[T] = R.size();
            C[k]++;
            R.push_back(S);
        }
        else C[MAPA[T]]++;
    }

    for (int i = 0; i < R.size(); i++) {
        string r = R[i];
        transform(r.begin(), r.end(), r.begin(), ::tolower);
        sort(r.begin(), r.end());
        if (C[MAPA[r]]==1) RET.push_back(R[i]);
    }

    sort(RET.begin(), RET.end());

    for (int i = 0; i < RET.size(); i++) printf("%s\n", RET[i].c_str());

    return 0;
}

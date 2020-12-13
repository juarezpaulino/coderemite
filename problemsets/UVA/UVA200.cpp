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

set<char> S;
vector<string> V;


int main() {

    char W[30];
    while (gets(W)) {
        if (*W=='#') break;
        V.push_back(W);
    }
    string ret;
    for (int j = 0; j <= 20; j++) for (int i = 0; i < V.size(); i++) if (j < V[i].size())
        if (!S.count(V[i][j])) ret += V[i][j], S.insert(V[i][j]);
    puts(ret.c_str());

    return 0;
}

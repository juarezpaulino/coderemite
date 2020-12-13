/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<string> V;
    set<string> H;
    string s;
    while (cin >> s) {
        V.push_back(s);
        H.insert(s);
    }
    for (int i = 0; i < V.size(); i++) {
        bool ok = 0;
        for (int j = 1; !ok && j < V[i].size()-1; j++)
            if (H.count(V[i].substr(0,j)) && H.count(V[i].substr(j)))
                ok = 1;
        if (ok) puts(V[i].c_str());
    }

    return 0;
}

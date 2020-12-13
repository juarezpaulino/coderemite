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

int T;
map<string, int> L;
char P[150];

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%s %*[^\n]\n", P);
        L[P]++;
    }

    for (map<string,int>::iterator it = L.begin(); it != L.end(); it++) {
        printf("%s %d\n", (it->first).c_str(), it->second);
    }

    return 0;
}

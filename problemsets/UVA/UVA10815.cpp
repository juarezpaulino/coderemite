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

set<string> D;
char S[1000];

int main() {

    char c;
    int k = 0;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) S[k++] = tolower(c);
        else if (k) { S[k] = 0; D.insert(S); k = 0; }
    }
    for (set<string>::iterator it = D.begin(); it != D.end(); it++) {
        printf("%s\n", (*it).c_str());
    }


    return 0;
}

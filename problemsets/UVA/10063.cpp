/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>

using namespace std;

int N;
char S[25];
char ret[25];
list<char> RET;

void go(int k) {
    list<char>::iterator it, it2;
    if (k == N) {
        int i = 0;
        for (it = RET.begin(); it != RET.end(); i++, it++) ret[i] = *it;
        ret[i] = 0; puts(ret);
        return;
    }
    bool done = 0;
    for (it = RET.begin(); !done; it++) {
        it2 = RET.insert(it, S[k]);
        go(k+1);
        RET.erase(it2);
        if (it == RET.end()) done = 1;
    }
}


int main() {

    int f = 1;
    while (scanf("%s", S) != EOF) {
        N = strlen(S);
        if (!f) putchar('\n');
        f = 0;
        go(0);
    }

    return 0;
}

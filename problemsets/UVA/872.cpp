/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int N;
char input[30];

vector<int> adj[128];
int in[128];
bool ok;

char ret[30];

void go(int k) {
    if (k == N) {
        ok = 1;
        printf("%c", ret[0]);
        for (int i = 1; i < N; i++) printf(" %c", ret[i]);
        puts("");
        return;
    }
    for (int i = 0; i < N; i++) {
        char c = input[i];
        if (in[c]==0) {
            in[c]--;
            for (int i = 0; i < adj[c].size(); i++) in[adj[c][i]]--;
            ret[k] = c;
            go(k+1);
            for (int i = 0; i < adj[c].size(); i++) in[adj[c][i]]++;
            in[c]++;
        }
    }
}


int main() {

    char S[10101];
    int T;
    scanf("%d ", &T);
    while (T--) {
        for (int i = 'A'; i <= 'Z'; i++) adj[i].clear(), in[i] = 0;

        N = 0;
        gets(S); istringstream is(S); char c;
        while (is >> c) input[N++] = c;
        sort(input, input+N);

        gets(S); is.clear(); is.str(S);
        string a;
        while (is >> a) { adj[a[0]].push_back(a[2]); in[a[2]]++; }

        ok = 0; go(0);

        if (!ok) puts("NO");
        if (T) putchar('\n');
        gets(S);
    }

    return 0;
}

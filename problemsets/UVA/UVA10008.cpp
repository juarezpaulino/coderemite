/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

pair<int, int> V[30];

bool comp(const pair<int, int> &A, const pair<int, int> &B) {
    if (A.first != B.first) return A.first > B.first;
    return A.second < B.second;
}

int main() {

    int N;
    char S[1000];
    scanf("%d ", &N);
    for (int i = 0; i < 30; i++) V[i] = make_pair(0,i);
    while (N--) {
        gets(S);
        for (int i = 0; S[i]; i++) {
            if (islower(S[i])) V[S[i]-'a'].first++;
            else if (isupper(S[i])) V[S[i]-'A'].first++;
        }
    }
    sort(V, V+30, comp);
    for (int i = 0; i < 30; i++) {
        if (V[i].first == 0) break;
        printf("%c %d\n", V[i].second + 'A', V[i].first);
    }

    return 0;
}

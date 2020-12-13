/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M;
string S;
vector<string> D;

bool cmp(const string &A, const string &B) {
    int a = 0, b = 0;
    for (int i = 0; i < M; i++) {
        if (A[i]!=S[i]) a++;
        if (B[i]!=S[i]) b++;
    }
    return a < b;
}

int main() {

    while (scanf("%d %d", &N, &M) != EOF) {
        D.clear();
        cin >> S;
        string s;
        for (int i = 1; i < N; i++) {
            cin >> s;
            D.push_back(s);
        }
        sort(D.begin(), D.end(), cmp);
        printf("%s\n", S.c_str());
        for (int i = 0; i < N-1; i++) printf("%s\n", D[i].c_str());
    }

    return 0;
}

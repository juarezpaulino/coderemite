/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

char c[100];

string resolve(vector<string> &S) {
    string ret, s1, s2, s3;
    int N = S.size();
    ret = S[0];
    for (int i = 1; i < N; ) {
        if (S[i]!="+" && S[i]!="-" && S[i]!="*" && S[i]!="/") ret += S[i++];
        else { ret += S[i+1] + S[i]; i+=2; }
    }
    return ret;
}

void resolve_back(vector<string> &S) {
    int k = S.size();
    string s1, s2, s3;
    if (k >= 3 && (S[k-2]=="*" || S[k-2]=="/")) {
        s3 = S.back(); S.pop_back();
        s2 = S.back(); S.pop_back();
        s1 = S.back(); S.pop_back();
        s1 += s3 + s2; S.push_back(s1);
    }
}

string expr() {
    vector<string> S;
    while (gets(c) && *c) {
        if (isdigit(*c)) { S.push_back(c); resolve_back(S); }
        else if (*c == '(') { S.push_back(expr()); resolve_back(S); }
        else if (*c == ')') break;
        else S.push_back(c);
    }
    return resolve(S);
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf(" ");
        string ret = expr();
        cout << ret << endl;
        if (T) cout << endl;
    }

    return 0;
}

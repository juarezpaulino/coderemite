/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, string> pss;

string replaceAll (string s, string f, string t) {
    string r;
    for  (int  p = 0 ; (p = s.find(f)) != s.npos;) {
        r += s.substr( 0 , p) + t;
        s = s.substr(p + f.size());
    }
    return  r + s;
}

int main() {

    char S[10101];
    int T;
    scanf("%d", &T);
    gets(S);
    gets(S);
    while (T--) {
        vector<pss> A;
        while (gets(S) && *S) {
            A.push_back(pss(S,S));
            A.back().second = replaceAll(A.back().second, " ", "");
            A.back().second = replaceAll(A.back().second, "\t", "");
            sort(A.back().second.begin(), A.back().second.end());
        }
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++) for (int j = i+1; j < A.size(); j++) if (A[i].second == A[j].second)
            printf("%s = %s\n", A[i].first.c_str(), A[j].first.c_str());
        if (T) putchar('\n');
    }

    return 0;
}

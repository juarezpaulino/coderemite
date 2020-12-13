/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>

using namespace std;

char S[10101];
int P[256], L[256];

string replaceAll (string s, string f, string t) {
    string r;
    for  (int  p = 0 ; (p = s.find(f)) != s.npos;) {
        r += s.substr( 0 , p) + t;
        s = s.substr(p + f.size());
    }
    return  r + s;
}

string replace1 (string s, string f, string t) {
    string r;
    int l = 0;
    for  (int  p = 0 ; (p = s.find(f,l)) != s.npos;) {
            if (p < s.size()-2 && s[p+2]>='a' && s[p+2]<='z') {
                P[s[p+2]] += (s[p]=='+') ? 1 : -1;
                l = 0;
            }
            else { l = p+2; continue; }
        r += s.substr( 0 , p) + t;
        s = s.substr(p + f.size());
    }
    return  r + s;
}

string replace2 (string s, string f, string t) {
    string r;
    for  (int  p = 0 ; (p = s.find(f)) != s.npos;) {
        L[s[p-1]] = (s[p]=='+') ? L[s[p-1]]+1 : L[s[p-1]]-1;
        r += s.substr( 0 , p) + t;
        s = s.substr(p + f.size());
    }
    return  r + s;
}


int main() {

    while (gets(S)) {
        char U[256] = {0};
        string a = S;
        a = replaceAll(a, " ", "");
        for (int i = 'a'; i <= 'z'; i++) P[i] = i-'a'+1;
        a = replace1(a, "++", "");
        a = replace1(a, "--", "");
        for (int i = 'a'; i <= 'z'; i++) L[i] = P[i];
        a = replace2(a, "++", "");
        a = replace2(a, "--", "");
        int p = 0;
        int ret =   (!a.size()) ? 0 :
                    (a[0]=='-') ? (p = 2, U[a[1]] = 1, -P[a[1]]) :
                    (a[0]=='+') ? (p = 2, U[a[1]] = 1, P[a[1]]) :
                    (p = 1, U[a[0]] = 1, P[a[0]]);
        for (int i = p; i < a.size(); i+=2) {
            ret += (a[i]=='+') ? P[a[i+1]] : -P[a[i+1]];
            U[a[i+1]] = 1;
        }
        printf("Expression: %s\n", S);
        printf("    value = %d\n", ret);
        for (int i = 'a'; i <= 'z'; i++) if (U[i]) {
            printf("    %c = %d\n", i, L[i]);
        }
    }

    return 0;
}

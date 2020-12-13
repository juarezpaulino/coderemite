/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <iostream>

using namespace std;

typedef pair<char,char> PCC;

map<PCC,PCC> A;

string add(string &a, string &b) {
    int m = max(a.size(), b.size()) + 1;
    if (a.size() < m) a = string(m-a.size(),'0') + a;
    if (b.size() < m) b = string(m-b.size(),'0') + b;
    string ret;
    char c = '0';
    for (int i = m-1; i >= 0; i--) {
        PCC r = A[PCC(c, a[i])];
        c = r.second;
        r = A[PCC(r.first, b[i])];
        c = A[PCC(c,r.second)].first;
        ret = string(1,r.first) + ret;
    }
    ret = string(1,c) + ret;
    int k = 0;
    while (k < ret.size()-1 && ret[k]=='0') k++;
    return ret.substr(k);
}

string left(string &a) {
    return a + string(1,'V');
}

string right(string &a) {
    return string(1,'V') + a.substr(0,a.size()-1);
}

void final(string &a) {
    a = string(8-a.size(), 'V') + a;
}

int main() {

    A[PCC('0','0')] = PCC('0','0');
    A[PCC('0','V')] = PCC('V','0');
    A[PCC('0','U')] = PCC('U','0');
    A[PCC('0','C')] = PCC('C','0');
    A[PCC('0','D')] = PCC('D','0');
    A[PCC('V','0')] = PCC('V','0');
    A[PCC('U','0')] = PCC('U','0');
    A[PCC('C','0')] = PCC('C','0');
    A[PCC('D','0')] = PCC('D','0');
    A[PCC('V','V')] = PCC('V','0');
    A[PCC('V','U')] = PCC('U','0');
    A[PCC('V','C')] = PCC('C','0');
    A[PCC('V','D')] = PCC('D','0');
    A[PCC('U','V')] = PCC('U','0');
    A[PCC('U','U')] = PCC('C','0');
    A[PCC('U','C')] = PCC('D','0');
    A[PCC('U','D')] = PCC('V','U');
    A[PCC('C','V')] = PCC('C','0');
    A[PCC('C','U')] = PCC('D','0');
    A[PCC('C','C')] = PCC('V','U');
    A[PCC('C','D')] = PCC('U','U');
    A[PCC('D','V')] = PCC('D','0');
    A[PCC('D','U')] = PCC('V','U');
    A[PCC('D','C')] = PCC('U','U');
    A[PCC('D','D')] = PCC('C','U');

    puts("COWCULATIONS OUTPUT");
    int N;
    scanf("%d", &N);
    while (N--) {
        char N1[10], N2[10];
        scanf("%s %s", N1, N2);
        string n1 = N1, n2 = N2;
        for (int i = 0; i < 3; i++) {
            scanf("%s", N2);
            if (*N2=='A') n2 = add(n2,n1);
            else if (*N2=='L') n2 = left(n2);
            else if (*N2=='R') n2 = right(n2);
        }
        final(n2);
        scanf("%s", N2);
        if (n2 == N2) puts("YES");
        else puts("NO");
    }
    puts("END OF OUTPUT");

    return 0;
}

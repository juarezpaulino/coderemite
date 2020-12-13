/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cctype>

using namespace std;

vector<string> code;
vector<string> L;
vector<double> C;

int main() {

    char S[1919];
    while (gets(S)) {
        if (S == string("000000")) break;
        char *p = S;
        string cod = "";
        while (*p != ' ') cod += *(p++);
        code.push_back(cod);
        p++;
        string l = "";
        while (*p != '$') l += *(p++);
        L.push_back(l);
        p++;
        double c;
        sscanf(p, "%lf", &c);
        C.push_back(c);
    }
    while (scanf("%s", S)) {
        if (S == string("#")) break;
        int m;
        scanf("%d", &m);
        int k = -1;
        string s = S;
        if (S[0] != '0') {
            printf("%-16s%-20s%15s%5d%6.2lf%7.2lf\n",S,"Local",S,m,0.00,0.00);
            continue;
        }
        bool ok = 0;
        for (int i = 0; i < code.size(); i++) if (s.size() >= code[i].size() && s.substr(0, code[i].size()) == code[i]) {
            string id = s.substr(code[i].size());
            if (id.size() < 4 || (id.size() > 10 && s[1]=='0') || (id.size()>7 && s[1]!='0')) continue;
            printf("%-16s%-25s%10s%5d%6.2lf%7.2lf\n",S,L[i].c_str(),id.c_str(),m,C[i]/100.,C[i]*m/100.);
            ok = 1;
            break;
        }
        if (!ok) printf("%-16s%-35s%5d%13.2lf\n",S,"Unknown",m,-1.00);
    }

    return 0;
}

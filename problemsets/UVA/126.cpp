/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

struct PII {
    int x, y;
    bool operator<(const PII &B) const {
        if (x != B.x) return x > B.x;
        return y < B.y;
    }
};

char S[1010];
int p, c, px, py;
map<PII, int> mapa, mapa1, mapa2;

int read_int() {
    int s = 0, ret = 0;
    if (S[p]=='+') p++;
    if (S[p]=='-') s = 1, p++;
    while (isdigit(S[p])) ret = ret * 10 + S[p++]-'0';
    if (ret == 0) ret = 1;
    if (s) ret *= -1;
    return ret;
}

void read_var() {
    px = 0; py = 0;
    bool x;
    while (S[p]=='x' || S[p]=='y') {
        if (S[p]=='y') x = 0;
        else x = 1;
        p++;
        if (isdigit(S[p])) {
            if (x) px = read_int();
            else py = read_int();
        }
        else {
            if (x) px = 1;
            else py = 1;
        }
        x = 1;
    }
}

void expr(map<PII, int> &mapa) {
    while (S[p]) {
        c = read_int();
        read_var();
        mapa[(PII){px,py}] += c;
    }
}

int main() {

    while (gets(S)) {
        if (*S=='#') break;
        mapa.clear(); mapa1.clear(); mapa2.clear();

        p = 0; expr(mapa1);
        gets(S); p = 0; expr(mapa2);

        for (map<PII,int>::iterator it1 = mapa1.begin(); it1 != mapa1.end(); it1++)
            for (map<PII,int>::iterator it2 = mapa2.begin(); it2 != mapa2.end(); it2++)
                mapa[(PII){it1->first.x+it2->first.x, it1->first.y+it2->first.y}] += it1->second * it2->second;

        bool first = 1;
        string RET[2];
        int n;
        char num[101];
        for (map<PII,int>::iterator it = mapa.begin(); it != mapa.end(); it++) {
            c = it->second; px = it->first.x; py = it->first.y;
            if (c == 0) continue;
            if (first) {
                if (c == 1 && (px || py)) ;
                else if (c == -1) RET[1] += '-', RET[0] += ' ';
                else { sprintf(num, "%d", c); n = strlen(num); RET[1] += num; RET[0] += string(n,' '); }
                first = 0;
            }
            else {
                if (c >= 0) RET[1] += " + ", RET[0] += string(3,' ');
                else RET[1] += " - ", RET[0] += string(3, ' ');
                if (abs(c) == 1 && (px || py)) ;
                else { sprintf(num, "%d", abs(c)); n = strlen(num); RET[1] += num; RET[0] += string(n,' '); }
            }
            if (px) {
                RET[1] += "x"; RET[0] += " ";
                if (px != 1) { sprintf(num, "%d", px); n = strlen(num); RET[0] += num; RET[1] += string(n,' '); }
            }
            if (py) {
                RET[1] += "y"; RET[0] += " ";
                if (py != 1) { sprintf(num, "%d", py); n = strlen(num); RET[0] += num; RET[1] += string(n,' '); }
            }
        }
        if (first) puts(" \n0");
        else {
            puts(RET[0].c_str());
            puts(RET[1].c_str());
        }
    }

    return 0;
}

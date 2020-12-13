/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

using namespace std;

int M[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};

int get_day2(int m, int d, int y, int by) {
    int ret = d, i;
    for (i = by; i < y; i++) ret += 365 + ((i%4==0) ? 1 : 0);
    for (i = 1; i < m; i++) ret += M[i] + ((i==2 && (y%4==0)) ? 1 : 0);
    return ret;
}

void set_day(int &m, int &d, int &y, int by, int z) {
    y = by, m = 1, d = 1;
    while (1) {
        int v = 365 + (((y%4==0&&y%100) || y%400==0) ? 1 : 0);
        if (z - v < 0) break;
        z -= v;
        y++;
    }
    while (1) {
        int v = M[m] + ((m==2 && ((y%4==0&&y%100) || y%400==0)) ? 1 : 0);
        if (z - v < 0) break;
        z -= v;
        m++;
    }
    d += z;
}


vector<string> tokenize(string s, string ch) {
    vector<string> ret;
    for(int p = 0, p2; p < (int)s.size(); p=p2+1) {
        p2 = s.find_first_of(ch, p);
        if(p2==-1) p2 = s.size();
        if(p2-p > 0) ret.push_back(s.substr(p, p2-p));
    }
    return ret;
}

int main() {

    char S[1010];
    int d, m, y;
    while (gets(S)) {
        vector<string> tok = tokenize(S,"-");
        sscanf(tok[0].c_str(), "%d", &y);
        sscanf(tok[1].c_str(), "%d", &m);
        sscanf(tok[2].c_str(), "%d", &d);
        int w = get_day2(m,d,y,0)-2;
        set_day(m,d,y,0,w);
        printf("%02d-%02d-%02d\n", y, m, d);
    }

    return 0;
}

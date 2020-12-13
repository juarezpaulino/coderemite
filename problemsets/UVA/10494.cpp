/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string D[10];

void fix(string &a) {
    int k = 0;
    while (k < a.size() && a[k]=='0') k++;
    a = (k == a.size()) ? "0" : a.substr(k);
}

int cmp(string &a, string &b) {
    fix(a); fix(b);
    int na = a.size(), nb = b.size();
    return (na > nb) ? 1 : (na < nb) ? -1 : (a > b) ? 1 : (a < b) ? -1 : 0;
}

string add(string &a, string &b) {
    fix(a); fix(b);
    int m = max(a.size(), b.size());
    a = string(m-a.size(), '0') + a;
    b = string(m-b.size(), '0') + b;

    string ret;
    int c = 0;
    for (int i = m-1; i >= 0; i--) {
        c += a[i]+b[i]-2*'0';
        ret += '0'+(c%10);
        c /= 10;
    }
    ret += '0'+(c%10);
    reverse(ret.begin(), ret.end());
    fix(ret);

    return ret;
}

string sub(string &a, string &b) {
    fix(a); fix(b);
    b = string(a.size()-b.size(), '0') + b;

    string ret;
    int c = 0;
    for (int i = a.size()-1; i >= 0; i--) {
        if (a[i]+c >= b[i]) {
            ret += a[i]+c-b[i]+'0';
            c = 0;
        }
        else {
            ret += a[i]+c+10-b[i]+'0';
            c = -1;
        }
    }
    reverse(ret.begin(), ret.end());
    fix(ret);

    return ret;
}

void div(string &a, string &b, string &d, string &md) {
    md = d = "0";
    for (int k = 0; k < a.size(); ) {
        md += a[k++];
        int p = 1;
        while (p < 10 && cmp(D[p], md) <= 0) p++; p--;
        d += string(1, '0'+p);
        md = sub(md, D[p]);
    }
OUT:
    fix(d); fix(md);
}


int main() {

    string a, b, op;
    while (cin >> a >> op >> b) {
        D[0] = "0"; for (int i = 1; i <= 9; i++) D[i] = add(D[i-1], b);
        string d, m;
        div(a,b,d,m);
        if (op == "/") cout << d << endl;
        else cout << m << endl;
    }

    return 0;
}

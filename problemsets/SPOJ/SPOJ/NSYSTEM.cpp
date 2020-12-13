/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int N, RET;
char S[1000];

int decode(string S) {
    int ret = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        int mult = 1;
        if (S[i] >= '0' && S[i] <= '9') { mult = S[i]-'0'; i++; }
        if (S[i]=='m') ret += 1000*mult;
        if (S[i]=='c') ret += 100*mult;
        if (S[i]=='x') ret += 10*mult;
        if (S[i]=='i') ret += mult;
    }
    return ret;
}

string encode(int V) {
    int m = V/1000; V%=1000;
    int c = V/100; V%=100;
    int x = V/10; V%=10;
    int i = V;
    string ret;
    if (m >= 1) {
        if (m > 1) ret += string(1,'0'+m);
        ret += "m";
    }
    if (c >= 1) {
        if (c > 1) ret += string(1,'0'+c);
        ret += "c";
    }
    if (x >= 1) {
        if (x > 1) ret += string(1,'0'+x);
        ret += "x";
    }
    if (i >= 1) {
        if (i > 1) ret += string(1,'0'+i);
        ret += "i";
    }
    return ret;
}


int main() {

    scanf("%d ", &N);
    while (N--) {
        gets(S);
        istringstream IN(S);
        string s;
        RET = 0;
        while (IN >> s) RET += decode(s);
        cout << encode(RET) << endl;
    }

    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Big-Endian dynamic bitset.
//
struct bitnum {
    string v;
    void fix() {
        int k = 0;
        while (v[k]=='0' && k < (int)v.size()-1) k++;
        v = v.substr(k);
    }
    void lead_zero(int N) { v = string(N-v.size(), '0') + v; }
    bitnum() {};
    bitnum(string s) : v(s) { fix(); }
    bitnum operator !() {
        bitnum ret = *this;
        for (int i = 0; i < (int)v.size(); i++) ret.v[i] = (!(v[i]-'0')) + '0';
        ret.fix();
        return ret;
    }
    friend bitnum shr(bitnum &A) {
        bitnum ret = A;
        if (ret.v.size() > 1) ret.v.erase(ret.v.end()-1);
        else ret.v[0] = '0';
        ret.fix();
        return ret;
    }
    friend bitnum shl(bitnum &A) {
        bitnum ret = A;
        ret.v.push_back('0');
        ret.fix();
        return ret;
    }
    bitnum operator^(bitnum A) {
        bitnum ret;
        int N = max(v.size(), A.v.size());
        lead_zero(N); A.lead_zero(N);
        ret.v.resize(N);
        for (int i = 0; i < N; i++) ret.v[i] = ((v[i]-'0')^(A.v[i]-'0')) + '0';
        ret.fix();
        return ret;
    }
    bitnum operator&(bitnum A) {
        bitnum ret;
        int N = max(v.size(), A.v.size());
        lead_zero(N); A.lead_zero(N);
        ret.v.resize(N);
        for (int i = 0; i < N; i++) ret.v[i] = ((v[i]-'0')&(A.v[i]-'0')) + '0';
        ret.fix();
        return ret;
    }
    bitnum operator|(bitnum A) {
        bitnum ret;
        int N = max(v.size(), A.v.size());
        lead_zero(N); A.lead_zero(N);
        ret.v.resize(N);
        for (int i = 0; i < N; i++) ret.v[i] = ((v[i]-'0')|(A.v[i]-'0')) + '0';
        ret.fix();
        return ret;
    }
};

int T;
vector<string> TOK;
int p;

bitnum factor() {
    bitnum x;
    if (TOK[p][0]>='0'&&TOK[p][0]<='9') { x = bitnum(TOK[p]); p++; }
    else if (TOK[p]=="not") { p++; x = factor(); x = !x; }
    else if (TOK[p]=="shr") { p++; x = factor(); x = shr(x); }
    else if (TOK[p]=="shl") { p++; x = factor(); x = shl(x); }
    return x;
}

bitnum expr() {
    bitnum x, y, z;
    x = factor();
    while (p < (int)TOK.size() && (TOK[p]=="xor"||TOK[p]=="and"||TOK[p]=="or")) {
        string op = TOK[p];
        p++;
        y = factor();
        if (op=="xor") z = x^y;
        else if (op=="and") z = x&y;
        else z = x|y;
        x = z;
    }
    return x;
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
    scanf("%d ", &T);
    for (int t = 1; t <= T; t++) {
        gets(S);
        TOK = tokenize(S," ");
        p = 0;
        bitnum ret = expr();
        printf("Case %d: %s\n", t, ret.v.c_str());
    }

    return 0;
}

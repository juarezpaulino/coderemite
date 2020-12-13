/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;


string fill(char c, int n) {
    string s; while(n--) s += c; return s;
}

string toRoman(int n) {
    if(n < 4) return fill('I', n);
    if(n < 6) return fill('I', 5-n) + "V";
    if(n < 9) return string("V") + fill('I', n-5);
    if(n < 11) return fill('I', 10-n) + "X";
    if(n < 40) return fill('X', n/10) + toRoman(n%10);
    if(n < 60) return fill('X', 5-n/10) + 'L' + toRoman(n%10);
    if(n < 90) return string("L") + fill('X', n/10-5) + toRoman(n%10);
    if(n < 110) return fill('X', 10-n/10) + "C" + toRoman(n%10);
    if(n < 400) return fill('C', n/100) + toRoman(n%100);
    if(n < 600) return fill('C', 5-n/100) + 'D' + toRoman(n%100);
    if(n < 900) return string("D") + fill('C', n/100-5) + toRoman(n%100);
    if(n < 1100) return fill('C', 10-n/100) + "M" + toRoman(n%100);
    if(n < 4000) return fill('M', n/1000) + toRoman(n%1000);
    return "?";
}

int toDecimal(string v) {
    int ret = 0;
    int n = v.size();
    int i = 0;
    while (i < n) {
        if (v[i]=='M') { ret += 1000; i++; }
        else if (v[i]=='D') { ret += 500; i++; }
        else if (v[i]=='C') {
            if (i+1 < n && v[i+1]=='D') { ret += 400; i+=2; }
            else if (i+1 < n && v[i+1]=='M') { ret += 900; i+=2; }
            else while (v[i]=='C') { ret += 100; i++; }
        }
        else if (v[i]=='L') { ret += 50; i++; }
        else if (v[i]=='X') {
            if (i+1 < n && v[i+1]=='L') { ret += 40; i+=2; }
            else if (i+1 < n && v[i+1]=='C') { ret += 90; i+=2; }
            else while (v[i]=='X') { ret += 10; i++; }
        }
        else if (v[i]=='V') { ret += 5; i++; }
        else if (v[i]=='I') {
            if (i+1 < n && v[i+1]=='V') { ret += 4; i+=2; }
            else if (i+1 < n && v[i+1]=='X') { ret += 9; i+=2; }
            else while (v[i]=='I') { ret += 1; i++; }
        }
    }
    return ret;
}


int main() {

    char S[1010];
    while (gets(S)) {
        if (isdigit(*S)) printf("%s\n", toRoman(atoi(S)).c_str());
        else printf("%d\n", toDecimal(S));
    }

    return 0;
}

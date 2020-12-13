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
#include <map>

using namespace std;

string fill(char c, int n) {
    string s; while(n--) s += c; return s;
}

string toRoman(int n) {
    if(n < 4) return fill('i', n);
    if(n < 6) return fill('i', 5-n) + "v";
    if(n < 9) return string("v") + fill('i', n-5);
    if(n < 11) return fill('i', 10-n) + "x";
    if(n < 40) return fill('x', n/10) + toRoman(n%10);
    if(n < 60) return fill('x', 5-n/10) + 'l' + toRoman(n%10);
    if(n < 90) return string("l") + fill('x', n/10-5) + toRoman(n%10);
    if(n < 110) return fill('x', 10-n/10) + "c" + toRoman(n%10);
    if(n < 400) return fill('c', n/100) + toRoman(n%100);
    if(n < 600) return fill('c', 5-n/100) + 'D' + toRoman(n%100);
    if(n < 900) return string("D") + fill('c', n/100-5) + toRoman(n%100);
    if(n < 1100) return fill('c', 10-n/100) + "M" + toRoman(n%100);
    if(n < 4000) return fill('M', n/1000) + toRoman(n%1000);
    return "?";
}


int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        map<char, int> M;
        for (int k = 1; k <= N; k++) {
            string S = toRoman(k);
            for (int i = 0; i < S.size(); i++) M[S[i]]++;
        }
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", N, M['i'], M['v'], M['x'], M['l'], M['c']);
    }

    return 0;
}

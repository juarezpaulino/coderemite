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
#include <queue>

using namespace std;

char isPrime(int n) {
    int maxP, p;
    if (n < 0) return isPrime(-n);
    if (n < 5 || n%2 == 0 || n%3 == 0) return (n == 2 || n == 3 || n == 1);
    maxP = (int)sqrt(n)+2;
    for (p = 5; p < maxP; p += 6) if (n % p == 0 || n % (p+2) == 0) return 0;
    return 1;
}

char S[30];

int main() {

    while (gets(S)) {
        int P = 0;
        for (int i = 0; S[i]; i++) P += ((S[i]>='a'&&S[i]<='z') ? S[i]-'a'+1 : S[i]-'A'+27);
        if (isPrime(P)) puts("It is a prime word.");
        else puts("It is not a prime word.");
    }

    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <map>

#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()


using namespace std;


char isPrime(int n) {
    int maxP, p;
    if (n < 0) return isPrime(-n);
    if (n < 5 || n%2 == 0 || n%3 == 0) return (n == 2 || n == 3);
    maxP = (int)sqrt(n)+2;
    for (p = 5; p < maxP; p += 6) if (n % p == 0 || n % (p+2) == 0) return 0;
    return 1;
}


typedef map<int, int> prime_map;

void squeeze(prime_map &M, int &n, int p) { for (; n % p == 0; n /= p) M[p]++; }

prime_map factor(int n) {
    prime_map M;
    if (n < 0) return (factor(-n));
    if (n < 2) return M;

    squeeze(M, n, 2); squeeze(M, n, 3);

    int maxP = (int)sqrt(n)+2;
    for (int p = 5; p < maxP; p += 6) { squeeze(M, n, p); squeeze(M, n, p+2); }
    if (n > 1) M[n]++;
    return M;
}


prime_map m;

int main() {

    int n, s;
    int target;
    bool found;
    int uptwo;
    int c = 1;
    
    while (scanf("%d", &n) != EOF) {  
        m = factor(n);
        printf("Instancia %d\n", c++);
        s = m.size();
        if (s >= 4) { puts("sim\n"); continue; }
        else if (s == 3) target = 2;
        else if (s == 2) target = 5;
        else target = 8;
        found = false; uptwo = 0;
        foreach(it, all(m)) {
            if (it->second >= target) found = true;
            if (it->second >= 2) uptwo++;
        }
        
        if ((uptwo >= 2) || (found)) puts("sim\n");
        else puts("nao\n");
    }
    
    return 0;
}

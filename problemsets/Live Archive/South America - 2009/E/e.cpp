/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/***********************************************************************************************************/
/*                                 Declarations, macros, parser functions                                  */
/***********************************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define FOR(i,m,n) for((i)=(m);(i)<(n);(i)++)
#define FORE(i,m,n) for((i)=(m);(i)<=(n);(i)++)
#define ROF(i,m,n) for((i)=(m);(i)>=(n);(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a))
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())


inline string ITOA(int a) {
    char c[500]; sprintf(c, "%d", (a)); return string(c);
}

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PII;
typedef signed long long i64;
typedef unsigned long long u64;

#define EPS 1E-9
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1
#define PI 3.1415926535897932384626433832795

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}



int cwh_to_price(int cwh) {
    if (cwh<=100) return cwh*2;
    else if (cwh<=10000) return 100*2+(cwh-100)*3;
    else if (cwh<=1000000) return 100*2+(10000-100)*3+(cwh-10000)*5;
    return 100*2+(10000-100)*3+(1000000-10000)*5+(cwh-1000000)*7;
}

int main() {

    int A, B;
    int ct, c1, c2, m1, m2;
    int p1, p2, p;
    
    for(; scanf("%d %d", &A, &B) && A+B; ) {
        /* First get the right total consumption. */
        for(ct = 1; ; ct<<=1) {
            p = cwh_to_price(ct);
            if (p > A) break;
        }
        m1 = 0, m2 = ct;
        do {
            ct = (m1+m2)/2; p = cwh_to_price(ct);
            if (p > A) m2 = ct;
            else if (p < A) m1 = ct; 
        } while (p!=A);
        
        /* Then bsearch to get the final price. */
        m1 = 0; m2 = ct/2;
        do {
            c1 = (m1+m2)/2; c2 = ct-c1;
            p1 = cwh_to_price(c1); p2 = cwh_to_price(c2);
            if (p1 < p2-B) m1 = c1+1;
            else if (p1 > p2-B) m2 = c1-1; 
        } while (p1 != p2-B);
        
        printf("%d\n", p1);
    }    
    return 0;
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
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

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define TLE while(1);
#define RTE printf("%d", 1/0);

using namespace std;
typedef vector<int> VI; typedef vector<double> VD; typedef vector<string> VS;
typedef vector<vector<int> > VVI; typedef vector<vector<string> > VVS;
typedef set<int> SI; typedef set<double> SD; typedef set<string> SS;
typedef pair<int,int> PII;
typedef signed long long i64; typedef unsigned long long u64;

#define EPS 1E-14
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {
 
    char str[100], num[100];
    int b, n, m, s, i;
    while (scanf("%s %s", str, num) && strcmp(str, "end")) {
        if (*str=='t') {
            sscanf(str+2, "%d", &b); sscanf(num, "%d", &n);
            if (!n) { printf("0\n"); continue; }
            VI val;
            while(n) {
                if (n<0) m = (-b+(n%b))%b, val.PB(m), n = (n-m)/b;
                else m = n%b, val.PB(m), n/=b;
            }
            reverse(ALL(val));
            FOR(i, SI(val)) printf("%d", val[i]); putchar('\n');
        }
        else {
            sscanf(str+4, "%d", &b);
            for(i = s = 0; num[i]; i++) s=s*b+num[i]-'0';
            printf("%d\n", s);
        }
    }
    
    return 0;
}

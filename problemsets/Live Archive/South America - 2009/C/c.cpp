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
#include <cstring>
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





int main() {

    char code[1001];
    int dif[1001], n, i, j, k, m, ret;

    for(; gets(code), strcmp(code,"*");) {
        n = strlen(code); ret = 0;
        dif[0] = code[0]-'a';
        FOR(i,1,n) dif[i] = (code[i]-code[i-1]+26)%26;
        dif[i] = ('a'-code[i-1]+26)%26;
        while (1) {
            m = INF; FORE(i,0,n) if (dif[i]>0 && dif[i]<m) m=dif[i], j = i;
            if (m==INF) break;
            m = -1; FORE(i,0,n) if (i!=j && dif[i]>m) m=dif[i], k = i;
            ret++; dif[j]--; dif[k]=(dif[k]+1)%26;
        }
        printf("%d\n", ret);
    }

    return 0;
}

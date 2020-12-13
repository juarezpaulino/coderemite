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

#define FOR(i,m,n) for((i)=m;(i)<(n);(i)++)
#define FORN(i,m,n) for((i)=(n)-1;(i)>=m;(i)--)
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

#define MAX 20

int r, c;
char board[MAX][MAX];
char bill[MAX][MAX];
int mini;


int main() {

    int i, j, m, n, mask;
    for (; scanf("%d %d", &r, &c), r+c; ) {
        FOR(i,0,r) scanf("%s", board[i]); mask = 1<<c; mini = INF;
        FOR(m,0,mask) {
            FOR(i,0,r) FOR(j,0,c) bill[i][j] = board[i][j]=='X';
            n = 0;
            FOR(j,0,c) if ((1<<j)&m) {
                n++; bill[0][j]^=1; bill[1][j]^=1;
                if (j>0) bill[0][j-1]^=1; if (j<c-1) bill[0][j+1]^=1;
            }
            if (n>=mini) goto OUT;
            FOR(i,1,r) FOR(j,0,c) {
                if (bill[i-1][j]) {
                    n++; bill[i][j]^=1; if (i<r-1) bill[i+1][j]^=1;
                    if (j>0) bill[i][j-1]^=1; if (j<c-1) bill[i][j+1]^=1;
                }
                if (n>=mini) goto OUT;
            }
            FOR(j,0,c) if(bill[r-1][j]) break;
            if (j==c) mini<?=n;
OUT:;
        }
        if (mini==INF) printf("Damaged billboard.\n");
        else printf("You have to tap %d tiles.\n", mini);
    }
    return 0;
}

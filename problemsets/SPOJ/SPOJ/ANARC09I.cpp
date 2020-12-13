/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <cassert>


using namespace std;


#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define IT(V) (__typeof(V.begin()))
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SORT(M) sort(ALL(M))
template<class T> inline void SORTG(vector<T> &M) { sort(ALL(M), greater<T>()); }
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())

typedef long long i64;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 0x3F3F3F3F;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double DINF = 1E16;
const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int N, M;
int GAUSS_JORDAN(VVD &A, VD &B) {
    int M = SI(A), N = SI(A[0]);
    int r = 0;
    FOR(j,0,N) {
        // Choose non-null line.
        int i = r; while (i < M && !cmp(A[i][j])) i++;
        // No pivot found on this variable j.
        if (i == M) continue;
        // Change rows for pivot.
        swap(A[i], A[r]); swap(B[i], B[r]);
        // Reduce pivot to 1.
        double p = A[r][j];
        FOR(k,0,N) A[r][k] = A[r][k] / p;
        B[r] = B[r] / p;
        // Put column on Echelon form.
        FOR(i,0,M) if (i!=r) {
            double p = A[i][j];
            FOR(k,0,N) A[i][k] = A[i][k] - p*A[r][k];
            B[i] = B[i] - p*B[r];
        }
        r++;
    }

    FOR(j,r,M) if (cmp(B[j])) return -1;        // No solution.
    if (r < N) return 1;                        // Infinite solutions.
    return 0;                                   // Only one solution.
}


int main() {

    int W, H, D;
    double B[11][11];
    VVD MA; VD MB;
    double S[11][11];

    bool line = false;
    while (1) {
        scanf("%d %d %d", &W, &H, &D);
        if (!W && !H && !D) break;

        MA = VVD(H*W, VD(H*W, 0)); MB = VD(H*W, 0);
        M = 0;
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) scanf("%lf", &B[i][j]);
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
            double t = 0;
            for (int k = i-D; k <= i+D; k++) for (int l = j-D; l <= j+D; l++)
                if (k >= 0 && k < H && l >= 0 && l < W && abs(i-k)+abs(j-l) <= D) {
                    MA[M][k*W + l] = 1.; t+=1.;
                }
            MB[M] = B[i][j]*t;
            M++;
        }

        GAUSS_JORDAN(MA, MB);

        int k = 0;
        FOR(i,0,H) FOR(j,0,W) S[i][j] = MB[k++];

        // Print Solution
        if (line) putchar('\n');
        line = true;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                printf("%*.2lf", 8, S[i][j]);
                if (j < W-1) putchar(' ');
            }
            putchar('\n');
        }
    }

    return 0;
}

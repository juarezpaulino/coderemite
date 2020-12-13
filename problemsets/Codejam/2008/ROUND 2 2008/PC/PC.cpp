/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>


using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define SI(V) (int)V.size()
#define PB push_back

typedef long long i64;
typedef vector<int> VI;

const int INF = 0x3F3F3F3F;
const double DINF = 1E16;
const double EPS = 1E-7;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////////////////////////////////////////////////////////////

const int MAXV = 1000;

struct Ship { int x, y, z, p; };

Ship ship[MAXV];
int N;

double power(int x0, int y0, int z0, int p0, double x, double y, double z) {
    return (fabs(x0-x) + fabs(y-y0) + fabs(z-z0)) / p0;
}

double maximum(double x, double y, double z) {
    double ret = -DINF;
    FOR(i,0,N) ret = max(ret, power(ship[i].x,ship[i].y,ship[i].z,ship[i].p,x,y,z));
    return ret;
}


int main() {
    
//	freopen("C.in","r",stdin);
//	freopen("C-small-practice.in","r",stdin);freopen("C-small-practice.out","w",stdout);
	freopen("C-large-practice.in","r",stdin);freopen("C-large-practice.out","w",stdout);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        
        double best, x, y, z;
        
        // Read ship elements.
        scanf("%d", &N);
        FOR(i,0,N) {
            int x, y, z, p; scanf("%d%d%d%d", &x, &y, &z, &p);
            ship[i] = (Ship){x, y, z, p};
        }
        
        // Approximate an optimal position.
        // Média ponderada.
        double sx = 0, sy = 0, sz = 0, t = 0, k;
        FOR(i,0,N) k = 1./ship[i].p, t += k,
                   sx += ship[i].x*k, sy += ship[i].y*k, sz += ship[i].z*k;
        sx /= t; sy /= t; sz /= t;
        
        // Interatively compute better positions walking step units on each
        // adjacency.
        double STEP = 1;
        double cur = maximum(sx,sy,sz);
        best = cur+1;
        while (STEP > EPS) {
           FOR(dx,-1,2) FOR(dy,-1,2) FOR(dz,-1,2) {
                double np = maximum(sx+dx*STEP, sy+dy*STEP, sz+dz*STEP);
                if (cmp(np,best) < 0) {
                    best = np;
                    x = sx+dx*STEP, y = sy+dy*STEP, z = sz+dz*STEP;
                }
            }
            if (cmp(best,cur) < 0) sx = x, sy = y, sz = z, cur = best;
            else STEP /= 2;
        }
        
        printf("Case #%d: %.6lf\n", tc, cur);
    }

	return 0;
}

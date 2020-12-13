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

using namespace std;

const double EPS2 = 1E-6*1E-6;

const double PI = acos(-1);

double f, R, t, r, g;

inline double circle_segment(double rad, double th) {
    return rad*rad*(th - sin(th))/2;
}

double intersection(double x1, double y1, double x2, double y2) {
  // the normalized radius is 1
  if (x1*x1 + y1*y1 > 1) {
    return 0;
  }
  if (x2*x2 + y2*y2 < 1) {
    return (x2-x1) * (y2-y1);
  }
  // EPS2 = 1e-6 * 1e-6
  if ((x2-x1)*(y2-y1) < EPS2) {
    // this trick helps in doing 10 or 100 times less
    // iterations than we would need to get the same
    // precision if we just return 0;
    return (x2-x1) * (y2-y1) / 2;
  }
 
  double mx = (x1 + x2) / 2;
  double my = (y1 + y2) / 2;
 
  return intersection(x1, y1, mx, my) +
    intersection(mx, y1, x2, my) +
    intersection(x1, my, mx, y2) +
    intersection(mx, my, x2, y2);
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

        scanf("%lf%lf%lf%lf%lf",&f,&R,&t,&r,&g);
        
        // Only first quadrant is necessary.
        double rad = R-t-f;
        double area = 0.;
        for (double x1 = r+f; x1 < R-t-f; x1 += g+2*r)
            for (double y1 = r+f; y1 < R-t-f; y1 += g+2*r) {
                double x2 = x1 + g - 2*f;
                double y2 = y1 + g - 2*f;
                if (x1 >= x2 || y1 >= y2) continue;
                if (x1*x1 + y1*y1 >= rad*rad) continue;
                if (x2*x2 + y2*y2 <= rad*rad) area += (x2-x1) * (y2-y1);
                else area += intersection(x1/rad, y1/rad, x2/rad, y2/rad)*rad*rad;
            }

        printf("Case #%d: %.6lf\n", tc, 1. - area / (PI*R*R/4));
    }

	return 0;
}

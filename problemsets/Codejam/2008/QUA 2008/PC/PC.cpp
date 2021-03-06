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

const double PI = acos(-1);

double f, R, t, r, g;

////////////////////////////////////////////////////////////////////////////////
// �rea do segmento circular - apenas referente a corda, sem a parte triangular.
//          ***
//         *****
//        *  \/ *       (theta)
//         *   *
//           * 
inline double circle_segment(double rad, double th) {
    return rad*rad*(th - sin(th))/2;
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
                if (x2 <= x1 || y2 <= y1) continue;
                if (x1*x1 + y1*y1 >= rad*rad) continue;
                if (x2*x2 + y2*y2 <= rad*rad) {
                    // All points are inside circle.
                    area += (x2-x1)*(y2-y1);
                } else if (x1*x1 + y2*y2 >= rad*rad && x2*x2 + y1*y1 >= rad*rad) {
                    // Only (x1,y1) inside circle.
                    // Area do segmento circular mais metade do ret�ngulo.
                    area += circle_segment(rad, acos(x1/rad) - asin(y1/rad)) +
                            (sqrt(rad*rad - x1*x1)-y1) *
                            (sqrt(rad*rad - y1*y1)-x1) / 2;
                } else if (x1*x1 + y2*y2 >= rad*rad) {
                    // (x1,y1) and (x2,y1) inside circle.
                    // Area do segmento circular mais �rea quadrilatero (B*b)*h/2.
                    area += circle_segment(rad, acos(x1/rad) - acos(x2/rad)) +
                            (x2-x1) * (sqrt(rad*rad - x1*x1)-y1 +
                            sqrt(rad*rad - x2*x2)-y1) / 2;
                } else if (x2*x2 + y1*y1 >= rad*rad) {
                    // (x1,y1) and (x1,y2) inside circle.
                    area += circle_segment(rad, asin(y2/rad) - asin(y1/rad)) +
                            (y2-y1) * (sqrt(rad*rad - y1*y1)-x1 +
                            sqrt(rad*rad - y2*y2)-x1) / 2;
                } else {
                    // All except (x2,y2) inside circle.
                    area += circle_segment(rad, asin(y2/rad) - acos(x2/rad)) +
                            (x2-x1)*(y2-y1) -
                            (y2-sqrt(rad*rad - x2*x2)) *
                            (x2-sqrt(rad*rad - y2*y2)) / 2;
                }
            }
            
        printf("Case #%d: %.6lf\n", tc, 1. - area / (PI*R*R/4));
    }

	return 0;
}

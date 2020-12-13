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
#include <set>
#include <queue>

using namespace std;

inline double circle_arc(double rad, double th) {
    return rad*th;
}

inline double circle_chord(double rad, double th) {
    return 2.*rad*sin(th/2.);
}


int main() {

    int r, d;
    char S[10];
    while (scanf("%d %d %s", &r, &d, S) != EOF) {
        r += 6440;
        double deg = (S == string("min")) ? d/60. : d;
        if (deg > 180) deg = 360 - deg;
        double arc = circle_arc(r, deg*M_PI/180.);
        double chord = circle_chord(r, deg*M_PI/180.);
        printf("%.6lf %.6lf\n", arc, chord);
    }

    return 0;
}

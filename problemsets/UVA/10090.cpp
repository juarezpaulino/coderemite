/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

/*
 * In general, a solution to the linear diophantine equation ax + by = c has the form:
 * x = x0 + b/d t,
 * y = y0 - a/d t,
 * where (x0, y0) is any particular solution (which can be found by extended gcd), d = gcd(a, b), and t is an integer parameter.
 *
 * Let's investigate for which values of t the solution is feasible for our problem (x and y are non-negative):
 * x0 + b/d t >= 0, y0 - a/d t >= 0, a >= 0, b >= 0, =>
 * -x0*d/b <= t <= y0*d/a.
 * And since t must be an integer, we futher have: ceil(-x0*d/b) <= t <= floor(y0*d/a).
 * So, all the feasible values of t form an interval of consecutive integer values.
 *
 * Next, let's look at the cost function: c1 x + c2 y = (c1 x0 + c2 y0) + (c1 b/d - c2 a/d) t = (some const) + (another const) * t, i.e. it's linear in t, which means that its minimum and maximums can occur only at the boundary of feasible region.
 *
 * So, just check two points t=ceil(-x0*d/b), and t=floor(y0*d/a), and choose whichever one is cheaper.
 */

using namespace std;

long long N, N1, N2, C1, C2;


pair<long long,long long> find_bezout(long long x, long long y, long long &d) {
    if (!y) { d = x; return pair<long long,long long>(1, 0); }
    pair<long long,long long> u = find_bezout(y, x%y, d);
    return pair<long long, long long>(u.second, u.first - (x/y)*u.second);
}

int main() {

    while (scanf("%lld %lld %lld %lld %lld", &N, &C1, &N1, &C2, &N2)) {
        if (!N) break;
        long long d;
        pair<long long, long long> M = find_bezout(N1, N2, d);
        if (N % d != 0) puts("failed");
        else {
            N /= d; N1 /= d; N2 /= d;
            M.first *= N; M.second *= N;
            long long t1 = ceil(-(double)M.first / N2),
                      t2 = floor((double)M.second / N1);
            if (t1 > t2) puts("failed");
            else {
                long long A = C1 * (M.first + N2*t1) + C2 * (M.second - N1*t1);
                long long B = C1 * (M.first + N2*t2) + C2 * (M.second - N1*t2);
                if (A < B) printf("%lld %lld\n", M.first + N2*t1, M.second - N1*t1);
                else printf("%lld %lld\n", M.first + N2*t2, M.second - N1*t2);
            }
        }
    }

    return 0;
}

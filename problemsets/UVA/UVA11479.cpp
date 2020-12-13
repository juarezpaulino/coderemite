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
#include <numeric>

using namespace std;

int T;
long long A[3];

int main() {

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%lld %lld %lld", A, A+1, A+2);
        sort(A,A+3);
        printf("Case %d: ", t);
        if (A[0]+A[1] <= A[2]) printf("Invalid\n");
        else if (A[0]==A[1] && A[0]==A[2]) printf("Equilateral\n");
        else if (A[0]==A[1] || A[1]==A[2] || A[0]==A[2]) printf("Isosceles\n");
        else printf("Scalene\n");
    }

    return 0;
}

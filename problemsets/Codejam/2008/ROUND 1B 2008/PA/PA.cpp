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

#define FOR(i,a,b) for (int i = a; i < b; i++)

using namespace std;

typedef long long i64;

int main() {
    
//	freopen("A.in","r",stdin);
//	freopen("A-small-practice.in","r",stdin);freopen("A-small-practice.out","w",stdout);
	freopen("A-large-practice.in","r",stdin);freopen("A-large-practice.out","w",stdout);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        i64 n, A, B, C, D, X, Y, M;
        i64 BU[9] = {0};
        
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &n, &A, &B, &C, &D, &X, &Y, &M);
        for (int i = 0; i < n; i++) {
            BU[(X%3)*3 + (Y%3)]++;
            X = (A * X + B) % M;
            Y = (C * Y + D) % M;
        }
        
        i64 ret = 0;
        
        // All in same class.
        FOR(i,0,9) ret += BU[i]*(BU[i]-1)*(BU[i]-2)/6;
        
        // We dont count two from same class and one from different, since it's
        // not congruent to mod 3.
        
        // All in different classes.
        FOR(i,0,9) FOR(j,i+1,9) FOR(k,j+1,9) {
            if ( ((i/3)+(j/3)+(k/3))%3 == 0 &&
                 ((i%3)+(j%3)+(k%3))%3 == 0    )
                 ret += BU[i] * BU[j] * BU[k];
        }
            
        printf("Case #%d: %lld\n", tc, ret);
    }

	return 0;
}

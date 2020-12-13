/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
////////////////////////////////////////////////////////////////////////////////
// Números conjugados (3 + sqrt(5))^n.
//
// Compor X = (3 + sqrt(5))^n + (3 - sqrt(5))^n, com a = (3 + sqrt(5))^n,
// b = (3 - sqrt(5))^n. Notar que b é sempre menor que 1 e que X pela expansão
// binomial é um inteiro. Montar sequencia de an e representar a exponenciacao
// rápida em logn.


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
   
struct Mat { int V[2][2]; };

Mat mul(Mat A, Mat B) {
    Mat C; FOR(i,0,2) FOR(j,0,2) C.V[i][j] = 0;
    FOR(k,0,2) FOR(i,0,2) FOR(j,0,2) C.V[k][j] = (C.V[k][j] + A.V[k][i]*B.V[i][j]) % 1000;
    return C;
}

Mat FEXP(Mat A, int N) {
    if (N==1) return A;
    if (N%2) return mul(A, FEXP(A, N-1));
    Mat A1 = FEXP(A, N/2);
    return mul(A1, A1);
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

        int N; scanf("%d", &N);
        
        Mat A = { 3, 5, 1, 3 }; 
        
        A = FEXP(A, N);
        
        printf("Case #%d: %03d\n", tc, (2*A.V[0][0] + 999) % 1000);
    }

	return 0;
}

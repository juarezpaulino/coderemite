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


int main() {

    int N;
    scanf("%d", &N);
    while (N--) {
        int A[3];
        scanf("%d %d %d", A, A+1, A+2);
        sort(A, A+3);
        if (A[0] + A[1] <= A[2]) puts("Wrong!!");
        else puts("OK");
    }

    return 0;
}

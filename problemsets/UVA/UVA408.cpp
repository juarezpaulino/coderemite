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

int S, M;

int main() {

    while (scanf("%d %d", &S, &M) != EOF) {
        printf("%10d%10d    %s\n\n", S, M, (__gcd(S,M)==1)?"Good Choice":"Bad Choice");
    }

    return 0;
}

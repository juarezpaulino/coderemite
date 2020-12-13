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

int A, B;

int main() {

    while (scanf("%d", &A) != EOF) {
        B = ((A&0xFF)<<24) |  ((A&0xFF00)<<8) | ((A&0xFF0000)>>8) | ((A&0xFF000000)>>24);
        printf("%d converts to %d\n", A, B);
    }

    return 0;
}

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

int A, B, C, D;

int main() {

    while (scanf("%d %d %d %d", &A, &B, &C, &D)) {
        if (!(A|B|C|D)) break;
        int ret = 1080;
        ret += ((40+A-B)%40) * 9;
        ret += ((40+C-B)%40) * 9;
        ret += ((40+C-D)%40) * 9;
        printf("%d\n", ret);
    }

    return 0;
}

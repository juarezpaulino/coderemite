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

vector<int> S;

int main() {

    for (int i = 1, d; (d = i*i)  <= 100000; i++) S.push_back(d);
    int A, B;
    while (scanf("%d %d", &A, &B)) {
        if (!(A|B)) break;
        int ret = (int)(upper_bound(S.begin(), S.end(), B) - lower_bound(S.begin(), S.end(), A));
        printf("%d\n", ret);
    }

    return 0;
}

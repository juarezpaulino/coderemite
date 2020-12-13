/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) sort(ALL(v)),(v).resize(unique(ALL(v))-(v).begin())

using namespace std;

struct rat {
    int num, den;
    bool operator<(const rat &B) const {
        int a = num*B.den, b = den*B.num;
        return a < b;
    }
    bool operator==(const rat &B) const {
        int a = num*B.den, b = den*B.num;
        return a == b;
    }
};

vector<rat> R;

int main() {

    R.push_back((rat){1,1});
    for (int i = 2; i <= 1000; i++) for (int j = 1; j < i; j++) R.push_back((rat){j,i});
    UNIQUE(R);
    for (int i = 0; i < R.size(); i++) {
        int d = __gcd(R[i].num, R[i].den);
        R[i].num /= d;
        R[i].den /= d;
    }

    int N, K;
    while (scanf("%d %d", &N, &K) != EOF) {
        for (int i = 0, j = 0; i < R.size(); i++) {
            if (R[i].num < N && R[i].den <= N) j++;
            if (j == K) { printf("%d/%d\n", R[i].num, R[i].den); break; }
        }
    }

    return 0;
}

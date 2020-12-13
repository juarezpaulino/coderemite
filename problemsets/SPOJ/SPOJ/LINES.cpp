/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int X[210], Y[210];

struct Slope {
    int dx, dy;
    bool operator==(const Slope &B) const {
        return this->dx*B.dy == this->dy*B.dx;
    }
} slope;

bool comp(const Slope &A, const Slope &B) {
    return A.dy * B.dx < B.dy * A.dx;
}

int main() {

    while (1) {
        scanf("%d", &N); if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d %d", X+i, Y+i);
        vector<Slope> slope;
        slope.resize(N*(N+1)/2);
        M = 0;
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
            int dx = X[i]-X[j], dy = Y[i]-Y[j];
            if (dy < 0) dy*=-1, dx*=-1;
            if (dy==0) dx = abs(dx);
            if (dx==0 && dy==0) continue;
            slope[M++] = (Slope){dx, dy};
        }
        slope.resize(M);
        sort(slope.begin(), slope.end(), comp);
        slope.resize(unique(slope.begin(),slope.end())-slope.begin());
        printf("%d\n", slope.size());
    }

    return 0;
}

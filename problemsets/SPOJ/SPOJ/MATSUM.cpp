/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<cstdio>
#include <vector>

using namespace std;

#define SI(V) (int)(V.size())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;

VVI BIT;
VVI FREQ;

inline void bit_init(int M, int N) {
    BIT.resize(M+2);
    FREQ.resize(M+2);
    for (int i = 0; i < M+2; i++) {
        BIT[i] = VI(N+2, 0);
        FREQ[i] = VI(N+2, 0);
    }
}

inline void bit_add(int y, int x, int v){
    y++; x++;
	while (y <= SI(BIT)){
		int x1 = x;
		while (x1 <= SI(BIT[y])) { BIT[y][x1] += v; x1 += (x1 & -x1); }
		y += (y & -y);
	}
}

inline int bit_get(int y, int x) {
    y++; x++;
    int ret = 0;
    while (y) {
        int x1 = x;
        while (x1) { ret += BIT[y][x1]; x1 &= x1 - 1; }
        y &= y - 1;
    }
    return ret;
}

inline int bit_get_interval(int y1, int x1, int y2, int x2) {
    return bit_get(y2, x2) - bit_get(y1-1, x2) - bit_get(y2, x1-1) + bit_get(y1-1, x1-1);
}

inline void bit_set(int y, int x, int v){
    int d = v-FREQ[y][x];
    bit_add(y, x, d);
    FREQ[y][x] = v;
}

inline void bit_scale(int c) {
    for (int i = 0; i < SI(BIT); i++)
        for (int j = 0; j < SI(BIT[i]); j++) {
            BIT[i][j] *= c;
            FREQ[i][j] *= c;
        }
}



int main() {

    int T, N;
    char S[1000];

    scanf("%d", &T);

    while (T--) {

        scanf("%d", &N);
        bit_init(N, N);

        while (1) {
            scanf("%s", S);
            if (!strcmp(S, "SET")) {
                int x, y, v;
                scanf("%d %d %d", &x, &y, &v);
                bit_set(y, x, v);
            }
            else if (!strcmp(S, "SUM")) {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int ret = bit_get_interval(y1, x1, y2, x2);
                printf("%d\n", ret);
            }
            else if (!strcmp(S, "END")) break;
        }

        putchar('\n');
    }

    return 0;
}

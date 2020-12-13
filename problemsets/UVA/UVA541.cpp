/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int M[100][100], N;

int main() {

    while (scanf("%d",&N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &M[i][j]);
        int r = 0, c = 0;
        int ri, ci;
        for (int i = 0; i < N; i++) {
            int k = 0;
            for (int j = 0; j < N; j++) if (M[i][j]) k++;
            if (k%2) r++, ri = i+1;
        }
        for (int i = 0; i < N; i++) {
            int k = 0;
            for (int j = 0; j < N; j++) if (M[j][i]) k++;
            if (k%2) c++, ci = i+1;
        }
        if (!(r|c)) puts("OK");
        else if (r==1&&c==1) printf("Change bit (%d,%d)\n", ri, ci);
        else puts("Corrupt");
    }

    return 0;
}

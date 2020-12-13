/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;


char V[] = "AUEOI";
char C[] = "JSBKTCLDMVNWFXGPYHQZR";


int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        printf("Case %d: ", t);
        int v = 0, c = 0, vp = 0, cp = 0;
        string s1 = "", s2 = "";
        for (int i = 0; i < N; i++)
            if (i&1) {
                s2 += C[cp];
                if (++c == 5) c = 0, cp++;
            }
            else {
                s1 += V[vp];
                if (++v == 21) v = 0, vp++;
            }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < N; i++)
            if (i&1) putchar(s2[i>>1]);
            else putchar(s1[i>>1]);
        putchar('\n');
    }
}

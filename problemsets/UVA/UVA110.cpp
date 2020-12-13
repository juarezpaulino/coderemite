/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N;
int V[10];

void go(int k) {
    if (k == N-1) {
        for (int i = 0; i < N; i++) putchar('\t');
        printf("writeln(%c", V[0]+'a');
        for (int i = 1; i < N; i++) printf(",%c", V[i]+'a');
        printf(")\n");
        return;
    }
    for (int i = k+1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) putchar('\t');
        if (i == k+1) printf("if %c < %c then\n", 'a'+V[i-1], 'a'+k+1);
        else if (i == 0) printf("else\n");
        else printf("else if %c < %c then\n", 'a'+V[i-1], 'a'+k+1);

        go(k+1);

        if (i != 0) swap(V[i], V[i-1]);
    }

    for (int i = 0; i <= k; i++) swap(V[i], V[i+1]);
}

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) V[i] = i;

        printf("program sort(input,output);\n");
        printf("var\n");
        printf("a");
        for (int i = 1; i < N; i++) printf(",%c", 'a'+i);
        printf(" : integer;\n");
        printf("begin\n");
        printf("\treadln(a");
        for (int i = 1; i < N; i++) printf(",%c", 'a'+i);
        printf(");\n");
        go(0);
        printf("end.\n");
        if (T != 0) putchar('\n');
    }


    return 0;
}

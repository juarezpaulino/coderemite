/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
    #include <cstdio>
    #include <cstring>
    #include <vector>
    #include <string>

    using namespace std;


    int main() {

        char S[1010];
        int T;
        scanf("%d ", &T);
        for (int t = 1; t <= T; t++) {
            int a[2] = {0};
            gets(S);
            int k = 0;
            for (int i = 0; S[i]; i++) {
                bool ok = 0;
                while (S[i]>='0' && S[i]<='9') {
                    a[k] = a[k]*10 + S[i]-'0';
                    ok = 1;
                    i++;
                }
                if (ok) k++;
            }
            double ret = a[0]*.5 + a[1]*.05;
            printf("Case %d: %g\n", t, ret);
        }

        return 0;
    }

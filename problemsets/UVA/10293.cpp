/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main() {

    char S[1010];
    while (gets(S)) {
        while (!*S) if (!gets(S)) return 0;
        map<int,int> M;
        int k = 0;
        do {
            while (!*S) if (!gets(S)) return 0;
            if (*S=='#') break;
            char *pt = strtok(S, " \t\v.?!,");
            while (pt) {
                int n = strlen(pt), l = 0;
                for (int i = 0; pt[i]; i++) if (pt[i]=='\'' || pt[i]=='-') l++;
                char c = pt[n-1];
                n-=l;
                pt = strtok(NULL, " \t\v.?!,");
                if (c=='-' && pt==NULL) k += n;
                else M[n+k]++, k = 0;
            }
        } while (gets(S));
        for (map<int,int>::iterator it = M.begin(); it != M.end(); it++) printf("%d %d\n", it->first, it->second);
        putchar('\n');
    }

    return 0;
}

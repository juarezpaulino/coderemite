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

char s1[110], s2[110], s3[110], s4[110], s5[110], S[110];
int T;

int main() {

    scanf("%d%*c", &T);
    while (T--) {
        *s1 = *s2 = *s3 = *s4 = *s5 = 0;
        scanf("%[^<]<", s1); if (!*s1) getchar();
        scanf("%[^>]>", s2); if (!*s2) getchar();
        scanf("%[^<]<", s3); if (!*s3) getchar();
        scanf("%[^>]>", s4); if (!*s4) getchar();
        scanf("%[^\n]\n", s5); if (!*s5) getchar();
        gets(S);
        string s = S;
        s.replace(s.size()-3, 3, string(s4)+string(s3)+string(s2)+string(s5));
        printf("%s%s%s%s%s\n", s1, s2, s3, s4, s5);
        printf("%s\n", s.c_str());
    }

    return 0;
}

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

int K, E;

string W[50];
string S[50];
string O[50];
int RET[50];

int main() {

    char s[100];
    int T = 1;
    while (scanf("%d %d", &K, &E) != EOF) {
        for (int i = 0; i < K; i++) scanf("%s ", s), W[i] = s;
        for (int i = 0; i < E; i++) {
            gets(s);
            O[i] = s;
            transform(s, s+strlen(s), s, ::tolower);
            S[i] = s;
        }
        printf("Excuse Set #%d\n", T++);
        int ret = -1;
        for (int i = 0; i < E; i++) {
            RET[i] = 0;
            for (int j = 0; j < K; j++) {
                string s = S[i];
                int p;
                while ((p = s.find(W[j])) != -1) {
                    int l = p + W[j].size();
                    if ((p==0 || !isalpha(s[p-1])) && (l==s.size() || !isalpha(s[l])))
                        RET[i]++;
                    s = s.substr(p+W[j].size());
                }
            }
            if (RET[i] > ret) ret = RET[i];
        }
        for (int i = 0; i < E; i++) if (RET[i]==ret) printf("%s\n", O[i].c_str());
        putchar('\n');
    }

    return 0;
}

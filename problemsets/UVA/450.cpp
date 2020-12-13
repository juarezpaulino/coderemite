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
#include <vector>

using namespace std;

struct data {
    string s[8];
};

vector<int> I;
vector<data> D;

bool cmp(const int &A, const int &B) {
    return D[A].s[3] < D[B].s[3];
}

int main() {

    int N, M = 0;
    scanf("%d ", &N);
    while (N--) {
        char dep[1010], S[1010], *s;
        if (!gets(dep)) break;
        while (gets(S)) {
            if (!*S) break;
            s = strtok(S,",");
            data d;
            d.s[0] = dep;
            for (int i = 1; i < 8; i++) {
                d.s[i] = s;
                s = strtok(NULL,",");
            }
            D.push_back(d);
            I.push_back(M++);
        }
    }
    sort(I.begin(), I.end(), cmp);
    for (int i = 0; i < M; i++) {
        puts("----------------------------------------");
        printf("%s %s %s\n", D[I[i]].s[1].c_str(), D[I[i]].s[2].c_str(), D[I[i]].s[3].c_str());
        printf("%s\n", D[I[i]].s[4].c_str());
        printf("Department: %s\n", D[I[i]].s[0].c_str());
        printf("Home Phone: %s\n", D[I[i]].s[5].c_str());
        printf("Work Phone: %s\n", D[I[i]].s[6].c_str());
        printf("Campus Box: %s\n", D[I[i]].s[7].c_str());
    }

    return 0;
}

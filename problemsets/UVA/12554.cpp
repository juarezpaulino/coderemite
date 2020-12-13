/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


string A[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

int main() {

    vector<string> B;
    char S[101];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", S);
        B.push_back(S);
    }
    int n = (((B.size()-1) / 16) + 1) * 16;
    for (int i = 0; i < n; i++)
        printf("%s: %s\n", B[i%B.size()].c_str(), A[i%16].c_str());

    return 0;
}

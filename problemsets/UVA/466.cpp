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

int N;
vector<string> A, B;

vector<string> rotate(vector<string> &A) {
    vector<string> ret(N, string(N,' '));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        ret[j][i] = A[N-i-1][j];
    return A = ret;
}

vector<string> vert_mirror(vector<string> &A) {
    vector<string> ret(N, string(N,' '));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        ret[i][j] = A[N-i-1][j];
    return A = ret;
}

int main() {

    char S[101];
    int T = 1;
    while (scanf("%d ", &N) != EOF) {
        A.clear(), B.clear();
        for (int i = 0; i < N; i++) {
            scanf("%s", S); A.push_back(S);
            scanf("%s", S); B.push_back(S);
        }
        if (A == B) printf("Pattern %d was preserved.\n", T++);
        else if (rotate(A) == B) printf("Pattern %d was rotated 90 degrees.\n", T++);
        else if (rotate(A) == B) printf("Pattern %d was rotated 180 degrees.\n", T++);
        else if (rotate(A) == B) printf("Pattern %d was rotated 270 degrees.\n", T++);
        else if ((rotate(A), vert_mirror(A) == B)) printf("Pattern %d was reflected vertically.\n", T++);
        else if (rotate(A) == B) printf("Pattern %d was reflected vertically and rotated 90 degrees.\n", T++);
        else if (rotate(A) == B) printf("Pattern %d was reflected vertically and rotated 180 degrees.\n", T++);
        else if (rotate(A) == B) printf("Pattern %d was reflected vertically and rotated 270 degrees.\n", T++);
        else printf("Pattern %d was improperly transformed.\n", T++);
    }

    return 0;
}

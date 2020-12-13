/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

char P[20], Q[20];
int K, N;


int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%s %d", P, &K);
        N = strlen(P);

        // Check if its done.
        {
            set<int> used;
            strcpy(Q, P);
            for (int i = 0; i < N; i++) used.insert(Q[i]);
            if (used.size() == K) {
                printf("Caso %d: %s\n", t, Q);
                goto END;
            }
        }

        // Check for equal length.
        for (int i = N-1; i >= 0; i--) for (int k = P[i]+1; k <= '9'; k++) {
            set<int> used;
            strcpy(Q, P);

            Q[i] = k;

            for (int j = 0; j <= i; j++) used.insert(Q[j]);
            if (used.size() > K || used.size() + N-i-1 < K) continue;

            char next = '0';
            vector<char> c;
            while (used.size() < K) {
                if (used.count(next)) next++;
                else used.insert(next), c.push_back(next), next++;
            }

            int mini = *used.begin(), M = c.size();
            for (int j = i+1; j < N-M; j++) Q[j] = mini;
            for (int j = N-M; j < N; j++) Q[j] = c[j-N+M];

            printf("Caso %d: %s\n", t, Q);
            goto END;
        }

        // Check for upper length.
        {
        set<int> used;
        int L = max(N+1, K);

        Q[0] = '1'; used.insert('1');
        char next = '0';
        vector<char> c;
        while (used.size() < K) {
            if (used.count(next)) next++;
            else used.insert(next), c.push_back(next), next++;
        }
        int mini = *used.begin(), M = c.size();
        for (int j = 1; j < L-M; j++) Q[j] = mini;
        for (int j = L-M; j < L; j++) Q[j] = c[j-L+M];
        Q[L] = 0;

        printf("Caso %d: %s\n", t, Q);
        }
END:;
    }

    return 0;
}

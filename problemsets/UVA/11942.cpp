/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    puts("Lumberjacks:");
    while (N--) {
        bool ordered = true;
        int x, y;
        scanf("%d %d", &x, &y);
        int up = y-x;
        x = y;
        for (int i = 0; i < 8; i++) {
            scanf("%d", &y);
            int cur = y - x;
            if (cur * up < 0) ordered = false;
            x = y;
        }
        if (ordered) puts("Ordered");
        else puts("Unordered");
    }

    return 0;
}

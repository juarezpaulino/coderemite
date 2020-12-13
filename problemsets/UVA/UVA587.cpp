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

char S[1000];
char dir[10];

const double STEP = sqrt(.5);

int main() {

    int T = 1;
    while (gets(S)) {
        if (!strcmp(S,"END")) break;
        double y = 0, x = 0;
        int d, k;
        for (int i = 0; S[i]; ) {
            d = k = 0;
            while (S[i]>='0'&&S[i]<='9') d = (d*10) + S[i]-'0', i++;
            while (S[i]!=','&&S[i]!='.') dir[k++] = S[i++];
            dir[k] = 0;
            if (!strcmp(dir,"N")) y += d;
            else if (!strcmp(dir,"S")) y -= d;
            else if (!strcmp(dir,"E")) x += d;
            else if (!strcmp(dir,"W")) x -= d;
            else if (!strcmp(dir,"NE")) y += d*STEP, x += d*STEP;
            else if (!strcmp(dir,"NW")) y += d*STEP, x -= d*STEP;
            else if (!strcmp(dir,"SE")) y -= d*STEP, x += d*STEP;
            else if (!strcmp(dir,"SW")) y -= d*STEP, x -= d*STEP;
            i++;
        }
        printf("Map #%d\n", T++);
        printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
        printf("The distance to the treasure is %.3lf.\n\n", sqrt(y*y+x*x));
    }

    return 0;
}

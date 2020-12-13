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
#include <numeric>

using namespace std;

int T;

///////////////////////////////////////////////////////////////////////////////
// Uses for this kind of dice:
//
//    0
// 1  2  3  4
//    5
//
int ccw_x[] = { 0, 4, 5, 2 };
int ccw_y[] = { 1, 2, 3, 4 };
int ccw_z[] = { 0, 1, 5, 3 };

string ccw_rotate(char axis, string dice, int times) {
    string ret = dice;
    for (int k = 0; k < times; k++, dice = ret) for (int i = 0; i < 4; i++)
        switch (axis) {
            case 'X': case 'x': ret[ccw_x[i]] = dice[ccw_x[(i+3)%4]]; break;
            case 'Y': case 'y': ret[ccw_y[i]] = dice[ccw_y[(i+3)%4]]; break;
            case 'Z': case 'z': ret[ccw_z[i]] = dice[ccw_z[(i+3)%4]]; break;
        }
    return ret;
}

bool equal(string &a, string &b) {
    bool ok = false;
    // All top faces in-order.
    for (int t = 0; t < 6; t++) {
        string c = a;
        switch (t) {
            case 0: break;
            case 1: c = ccw_rotate('Z', c, 3); break;
            case 2: c = ccw_rotate('X', c, 1); break;
            case 3: c = ccw_rotate('Z', c, 1); break;
            case 4: c = ccw_rotate('X', c, 3); break;
            case 5: c = ccw_rotate('X', c, 2); break;
        }
        ok |= (c == b);
        for (int i = 0; i < 3; i++) {
            c = ccw_rotate('Y', c, 1);
            ok |= (c == b);
        }
    }
    return ok;
}


int main() {

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        char a[10], b[10];
        scanf("%s %s", a, b);
        string A = a, B = b;

        // Convert to standard library form.
        swap(A[1], A[3]); swap(A[3], A[5]);
        swap(B[1], B[3]); swap(B[3], B[5]);

        if (equal(A,B)) puts("Equal");
        else puts("Not Equal");
    }

    return 0;
}

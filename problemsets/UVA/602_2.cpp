/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int D[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char Mo[13][20] =    {
                    "",
                    "January",
                    "February",
                    "March",
                    "April",
                    "May",
                    "June",
                    "July",
                    "August",
                    "September",
                    "October",
                    "November",
                    "December"
                    };

char W[7][20] = {
                    "Monday",
                    "Tuesday",
                    "Wednesday",
                    "Thursday",
                    "Friday",
                    "Saturday",
                    "Sunday"
                };

int H[32][13][10001];

int main() {

    int w = 5;
    for (int y = 1999; y > 0; y--) {
        int l = (y > 1752) ? (y%4==0 && !(y%100==0 && y%400!=0)) ? 1 : 0 : (y%4==0) ? 1 : 0;
        for (int m = 12; m > 0; m--) for (int d = D[m]+((m==2) ? l : 0); d > 0; d--) {
            if (y == 1752 && m == 9 && d >= 3 && d <= 13) H[d][m][y] = -1;
            else {
                w = (w+6) % 7;
                H[d][m][y] = w;
            }
        }
    }
    w = 4;
    for (int y = 2000; y <= 10000; y++) {
        int l = (y > 1752) ? (y%4==0 && !(y%100==0 && y%400!=0)) ? 1 : 0 : (y%4==0) ? 1 : 0;
        for (int m = 1; m <= 12; m++) for (int d = 1; d <= D[m]+((m==2) ? l : 0); d++) {
            w = (w+1) % 7;
            H[d][m][y] = w;
        }
    }
    int d, m, y;
    while (scanf("%d %d %d", &m, &d, &y)) {
        if (!(d|m|y)) break;
        int leap = (y > 1752) ? (y%4==0 && !(y%100==0 && y%400!=0)) ? 1 : 0 : (y%4==0) ? 1 : 0;
        if (m < 1 || m > 12 || y <= 0 || d < 1 || d > D[m] + ((m==2) ? leap : 0) || H[d][m][y]==-1)
            printf("%d/%d/%d is an invalid date.\n", m, d, y);
        else printf("%s %d, %d is a %s\n", Mo[m], d, y, W[H[d][m][y]]);
    }


    return 0;
}

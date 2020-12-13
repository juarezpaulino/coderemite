/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>

char *child[2][4][4];
char *parent[2][4][4];


int main() {

    char ch;
    char sang[3][5];
    int n_sang[3];
    int p[3];
    char rh[3];
    int empty;
    int permuta;
    int per[2];
    int n_per;
    int c;
    int i;

    child[0][0][0] = "{A-, O-}";
    child[0][0][1] = child[0][1][0] = "{A-, B-, AB-, O-}";
    child[0][0][2] = child[0][2][0] = "{A-, B-, AB-}";
    child[0][0][3] = child[0][3][0] = "{A-, O-}";
    child[0][1][1] = "{B-, O-}";
    child[0][1][2] = child[0][2][1] = "{A-, B-, AB-}";
    child[0][1][3] = child[0][3][1] = "{B-, O-}";
    child[0][2][2] = "{A-, B-, AB-}";
    child[0][2][3] = child[0][3][2] = "{A-, B-}";
    child[0][3][3] = "O-";

    child[1][0][0] = "{A+, A-, O+, O-}";
    child[1][0][1] = child[1][1][0] = "{A+, A-, B+, B-, AB+, AB-, O+, O-}";
    child[1][0][2] = child[1][2][0] = "{A+, A-, B+, B-, AB+, AB-}";
    child[1][0][3] = child[1][3][0] = "{A+, A-, O+, O-}";
    child[1][1][1] = "{B+, B-, O+, O-}";
    child[1][1][2] = child[1][2][1] = "{A+, A-, B+, B-, AB+, AB-}";
    child[1][1][3] = child[1][3][1] = "{B+, B-, O+, O-}";
    child[1][2][2] = "{A+, A-, B+, B-, AB+, AB-}";
    child[1][2][3] = child[1][3][2] = "{A+, A-, B+, B-}";
    child[1][3][3] = "{O+, O-}";

    parent[0][0][0] = "{A+, B+, AB+, O+}";
    parent[0][0][1] = "{B+, AB+}";
    parent[0][0][2] = "{B+, AB+}";
    parent[0][0][3] = "{A+, B+, O+}";
    parent[0][1][0] = "{A+, AB+}";
    parent[0][1][1] = "{A+, B+, AB+, O+}";
    parent[0][1][2] = "{A+, AB+}";
    parent[0][1][3] = "{A+, B+, O+}";
    parent[0][2][0] = "{A+, B+, AB+, O+}";
    parent[0][2][1] = "{A+, B+, AB+, O+}";
    parent[0][2][2] = "{A+, B+, AB+}";
    parent[0][2][3] = parent[0][3][2] = "IMPOSSIBLE";
    parent[0][3][0] = "{A+, AB+}";
    parent[0][3][1] = "{B+, AB+}";
    parent[0][3][3] = "{A+, B+, O+}";

    parent[1][0][0] = "{A+, A-, B+, B-, AB+, AB-, O+, O-}";
    parent[1][0][1] = "{B+, B-, AB+, AB-}";
    parent[1][0][2] = "{B+, B-, AB+, AB-}";
    parent[1][0][3] = "{A+, A-, B+, B-, O+, O-}";
    parent[1][1][0] = "{A+, A-, AB+, AB-}";
    parent[1][1][1] = "{A+, A-, B+, B-, AB+, AB-, O+, O-}";
    parent[1][1][2] = "{A+, A-, AB+, AB-}";
    parent[1][1][3] = "{A+, A-, B+, B-, O+, O-}";
    parent[1][2][0] = "{A+, A-, B+, B-, AB+, AB-, O+, O-}";
    parent[1][2][1] = "{A+, A-, B+, B-, AB+, AB-, O+, O-}";
    parent[1][2][2] = "{A+, A-, B+, B-, AB+, AB-}";
    parent[1][2][3] = parent[1][3][2] = "IMPOSSIBLE";
    parent[1][3][0] = "{A+, A-, AB+, AB-}";
    parent[1][3][1] = "{B+, B-, AB+, AB-}";
    parent[1][3][3] = "{A+, A-, B+, B-, O+, O-}";

    c = 1;
    while (1) {

        for (i = 0; i < 3; i++)
            n_sang[i] = 0;

        i = 0;
        n_per = 0;
        while (i < 3) {
            ch = getchar();
            while (ch == ' ') ch = getchar();
            if (ch == 'E') return 0;
            else if (ch == '?') empty = i;
            else {
                sang[i][n_sang[i]++] = ch;
                ch = getchar();
                if ((ch == 'A') || (ch == 'B')) {
                    sang[i][n_sang[i]++] = ch;
                    ch = getchar();
                }
                sang[i][n_sang[i]] = '\0';
                rh[i] = ch;
                /* Mapeia a pessoa para usar a tabela */
                if (n_sang[i] == 2) p[i] = 2;
                else if (sang[i][0] == 'A') p[i] = 0;
                else if (sang[i][0] == 'B') p[i] = 1;
                else p[i] = 3;

                /* Associa o rh a permutacao */
                if (rh[i] == '+') per[n_per++] = 1;
                else per[n_per++] = 0;
            }
            i++;
        }

        while ((ch = getchar()) != '\n');

        if (empty == 2)
            permuta = per[0] | per[1];
        else {
            if ((!per[0]) && (per[1]))
                permuta = 0;
            else
                permuta = 1;
        }

        printf("Case %d: ", c);

        if (empty == 2)
            printf("%s%c %s%c %s\n", sang[0], rh[0], sang[1], rh[1], child[permuta][p[0]][p[1]]);
        else if (empty == 1)
            printf("%s%c %s %s%c\n", sang[0], rh[0], parent[permuta][p[0]][p[2]], sang[2], rh[2]);
        else
            printf("%s %s%c %s%c\n", parent[permuta][p[1]][p[2]], sang[1], rh[1], sang[2],rh[2]);

        c++;
    }

    return 0;
}

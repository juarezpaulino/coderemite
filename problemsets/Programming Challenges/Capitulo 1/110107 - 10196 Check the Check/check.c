/* Check the Check */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 8
#define MAXCOLUMN 8

char table[MAXLINE][MAXCOLUMN];
char kings[2][2];
#define WHITE 0
#define BLACK 1

int verify(int y, int x) {

    char piece;
    char king;
    char down, right;
    int i;

    piece = toupper(table[y][x]);
    if (isupper(table[y][x]))
        king = BLACK;
    else
        king = WHITE;
    
    switch (piece) {
        
        case 'P':
            if (king == BLACK) {
                if ((abs(x - kings[BLACK][1]) == 1) && ((y - kings[BLACK][0]) == 1))
                    return 1;
            }
            else {
                if ((abs(x - kings[WHITE][1]) == 1) && ((kings[WHITE][0] - y) == 1))
                    return 1;
            }
            break;
        case 'N':
            if (((abs(x - kings[king][1]) == 2) && (abs(y - kings[king][0]) == 1)) 
            || ((abs(x - kings[king][1]) == 1) && (abs(y - kings[king][0]) == 2)))
                return 1;
            break;
        case 'Q':
        case 'B':
            if (abs(y - kings[king][0]) == abs(x - kings[king][1])) {
                if (y < kings[king][0])
                    down = 1;
                else
                    down = -1;
                if (x < kings[king][1])
                    right = 1;
                else
                    right = -1;
                for (i = 1; y+(i*down) != kings[king][0]; i++)
                    if (table[y+(i*down)][x+(i*right)] != '.')
                        break;
                if (y+(i*down) == kings[king][0])
                    return 1;
            }
            if (piece == 'B')
                break;
        case 'R':
            if ((x == kings[king][1]) || (y == kings[king][0])) {
                if (x == kings[king][1]) {
                    right = 0;
                    if (y < kings[king][0])
                        down = 1;
                    else
                        down = -1;   
                }
                else {
                    down = 0;
                    if (x < kings[king][1])
                        right = 1;
                    else
                        right = -1;
                }
                for (i = 1; (x+(i*right) != kings[king][1]) || 
                (y+(i*down) != kings[king][0]); i++)
                    if (table[y+(i*down)][x+(i*right)] != '.')
                        break;
                if ((x+(i*right) == kings[king][1]) && (y+(i*down) == kings[king][0]))
                    return 1;
            }
    }
    
    return 0;
}


int main() {

    int i, j;
    int exit;
    int game;
    char cr, check_team;
    
    game = 1;
    while (1) {
        
        exit = 1;
        for (i = 0; i < MAXLINE; i++) {
            for (j = 0; j < MAXCOLUMN; j++) {
                cr = getchar();
                table[i][j] = cr;
                if (cr == 'K') {
                    kings[WHITE][0] = i;
                    kings[WHITE][1] = j;
                }
                if (cr == 'k') {
                    kings[BLACK][0] = i;
                    kings[BLACK][1] = j;
                }
                if ((cr != '.') && (exit))
                    exit = 0;
            }
            getchar();
        }
        getchar();
        if (exit)
            break;
        
        check_team = -1;
        for (i = 0; i < MAXLINE; i++)
            for (j = 0; j < MAXCOLUMN; j++)
                if ((table[i][j] != '.') && (table[i][j] != 'k') && 
                (table[i][j] != 'K'))
                    if (verify(i,j)) {
                        if (isupper(table[i][j]))
                            check_team = BLACK;
                        else
                            check_team = WHITE;
                        break;
                    } 
        
        if (check_team == BLACK)
            printf("Game #%d: black king is in check.\n", game);
        else if (check_team == WHITE)
            printf("Game #%d: white king is in check.\n", game);
        else
            printf("Game #%d: no king is in check.\n", game);
        game++;
    }
        
    return 0;
}

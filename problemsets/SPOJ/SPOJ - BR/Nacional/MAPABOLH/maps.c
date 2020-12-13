/* Maps.c */

#include <stdio.h>
#include <string.h>

char up(char cr) {
    if (cr == 's')
        return 'p';
    if (cr == 'r')
        return 'q';
    else
        return -1;
}

char down(char cr) {
    if (cr == 'p')
        return 's';
    if (cr == 'q')
        return 'r';
    else
        return -1;
}

char left(char cr) {
    if (cr == 'q')
        return 'p';
    if (cr == 'r')
        return 's';
    else
        return -1;
}

char right(char cr) {
    if (cr == 'p')
        return 'q';
    if (cr == 's')
        return 'r';
    else
        return -1;
}

int main() {
    
    int N;
    char region[5010];
    char upside[5010], downside[5010], leftside[5010], rightside[5010];
    int u, d, l, r, i, pos, lenght;
    
    scanf("%d", &N);
    getchar();
    
    while (N > 0) {
    
        gets(region);    
        *upside = *downside = *leftside = *rightside = '\0';
        u = d = r = l = 1;
        
        lenght = strlen(region);
        region[lenght] = '\0';
        
        /* Test the border. */
        for (i = 1; i < lenght; i++) {
            if ((region[i] != 'p') && (region[i] != 'q'))
                u = 0;
            if ((region[i] != 'p') && (region[i] != 's'))
                l = 0;
            if ((region[i] != 'q') && (region[i] != 'r'))
                r = 0;
            if ((region[i] != 'r') && (region[i] != 's'))
                d = 0;
            if ((u == 0) && (l == 0) && (r == 0) && (d == 0))
                break;
        }
        
        /* Check the up side of the map. */
        if (u)
            strcpy(upside, "<none>");
        else {
            switch(region[lenght - 1]) {
                case 'r':
                case 's':
                    for (i = 0; i < lenght - 1; i++)
                        upside[i] = region[i];
                    upside[i] = up(region[i]);
                    upside[i+1] = '\0';
                    break;
                case 'p':
                case 'q':
                    for (i = lenght - 1; i > 0; i--)
                        if ((region[i] == 'r') || (region[i] == 's')) {
                            pos = i;
                            break;
                        }
                    strncpy(upside, region, pos);
                    upside[pos] = up(region[pos]);
                    for (i = pos + 1; i < lenght; i++)
                        upside[i] = down(region[i]);
                    upside[i] = '\0';
                    break;
            }
        }
        
        /* Check the left side of the map. */
        if (l)
            strcpy(leftside, "<none>");
        else {
            switch(region[lenght - 1]) {
                case 'q':
                case 'r':
                    for (i = 0; i < lenght - 1; i++)
                        leftside[i] = region[i];
                    leftside[i] = left(region[i]);
                    leftside[i+1] = '\0';
                    break;
                case 'p':
                case 's':
                    for (i = lenght - 1; i > 0; i--)
                        if ((region[i] == 'q') || (region[i] == 'r')) {
                            pos = i;
                            break;
                        }
                    strncpy(leftside, region, pos);
                    leftside[pos] = left(region[pos]);
                    for (i = pos + 1; i < lenght; i++)
                        leftside[i] = right(region[i]);
                    leftside[i] = '\0';
                    break;
            }
        }
            
        /* Check the right side of the map. */
        if (r)
            strcpy(rightside, "<none>");
        else {
            switch(region[lenght - 1]) {
                case 'p':
                case 's':
                    for (i = 0; i < lenght - 1; i++)
                        rightside[i] = region[i];
                    rightside[i] = right(region[i]);
                    rightside[i+1] = '\0';
                    break;
                case 'q':
                case 'r':
                    for (i = lenght - 1; i > 0; i--)
                        if ((region[i] == 'p') || (region[i] == 's')) {
                            pos = i;
                            break;
                        }
                    strncpy(rightside, region, pos);
                    rightside[pos] = right(region[pos]);
                    for (i = pos + 1; i < lenght; i++)
                        rightside[i] = left(region[i]);
                    rightside[i] = '\0';
                    break;
            }
        }
        
        /* Check the down side of the map. */
        if (d)
            strcpy(downside, "<none>");
        else {
            switch(region[lenght - 1]) {
                case 'p':
                case 'q':
                    for (i = 0; i < lenght - 1; i++)
                        downside[i] = region[i];
                    downside[i] = down(region[i]);
                    downside[i+1] = '\0';
                    break;
                case 'r':
                case 's':
                    for (i = lenght - 1; i > 0; i--)
                        if ((region[i] == 'p') || (region[i] == 'q')) {
                            pos = i;
                            break;
                        }
                    strncpy(downside, region, pos);
                    downside[pos] = down(region[pos]);
                    for (i = pos + 1; i < lenght; i++)
                        downside[i] = up(region[i]);
                    downside[i] = '\0';
                    break;
            }
        }            
        
        printf("%s %s %s %s\n", upside, downside, leftside, rightside);
        
        N--;
    }
 
    return 0;   
}

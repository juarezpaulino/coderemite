/* Color Hash */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char configuration[25];
    char solution[17];
} table;

struct {
    table key[1000000];
    int max;
} hash;

char solution[] = {0,3,4,3,0,5,6,5,0,1,2,1,0,7,8,7,0,9,10,9,0,1,2,1,'\0'};

void construct_candidates(char c[], int *ncandidates, char last, int count);
void move(char dir, char wheel[]);

int stringcmp(const char a[], const char b[]) {
    
    int i;
    
    for (i = 0; i < 24; i++)
        if ((int)a[i] > (int)b[i])
            return 1;
        else if ((int)a[i] < (int)b[i])
            return -1;
    return 0;
}

int compare(const void *a, const void *b) {

    table *x, *y;
    
    x = (table *)a;
    y = (table *)b;
    
    return (stringcmp(x -> configuration, y -> configuration));
}

int binary_search(char wheel[], int min, int max) {

    int pos, comp;
    
    if (min > max)
        return -1;
    pos = (min + max) / 2;
    comp = stringcmp(wheel, hash.key[pos].configuration);
    if (comp == 0)
        return (pos);
    else if (comp < 0)
        return (binary_search(wheel, min, pos - 1));
    else
        return (binary_search(wheel, pos + 1, max));
}

void backtrack(char a[], char wheel[], int steps, char last, int count) {

    char c[4];
    int ncandidates, i, j, pos;

    if (steps > 14)
        return;
    else {
        steps++;
        construct_candidates(c, &ncandidates, last, count);
        for (i = 0; i < ncandidates; i++) {
            move(c[i], wheel);
            a[steps] = c[i];
            if (hash.max >= 0)
                qsort(hash.key, hash.max+1, sizeof(table), compare);
            if ((pos = binary_search(wheel, 0, hash.max)) != -1)
                continue;
            hash.max++;
            printf("%d\n", hash.max);
            a[steps+1] = '\0';
            memcpy(hash.key[hash.max].configuration, wheel, 25);
            strcpy(hash.key[hash.max].solution, a);
            if (c[i] == last)
                count++;
            else
                count = 1;
            backtrack(a, wheel, steps, c[i], count);
        }
    }
}

void construct_candidates(char c[], int *ncandidates, char last, int count) {

    char i, legal_move;
    
    *ncandidates = 0;
    for (i = '1'; i <= '4'; i++) {
        legal_move = 1;
        if (((i == '1') && (last == '3')) || ((i == '3') && (last == '1')) ||
        ((i == '2') && (last == '4')) || ((i == '4') && (last == '2'))) 
            legal_move = 0;
        if ((count == 6) && (last == i))
            legal_move = 0;
        if (legal_move) {
            c[*ncandidates] = i;
            (*ncandidates)++;
        }
    }
}

void move(char dir, char wheel[]) {

    char temp[25];
    int i;

    memcpy(temp, wheel, 25);
    switch (dir) {
        case '1':
            for (i = 2; i < 12; i++)
                wheel[i] = temp[i-2];
            wheel[0] = temp[10];
            wheel[1] = temp[11];
            wheel[23] = wheel[11];
            wheel[22] = wheel[10];
            wheel[21] = wheel[9];    
            break;
        case '2':
            for (i = 12; i < 22; i++)
                wheel[i] = temp[i+2];
            wheel[22] = temp[12];
            wheel[23] = temp[13];
            wheel[11] = wheel[23];
            wheel[10] = wheel[22];
            wheel[9] = wheel[21];
            break;
        case '3':
            for (i = 0; i < 10; i++)
                wheel[i] = temp[i+2];
            wheel[10] = temp[0];
            wheel[11] = temp[1];
            wheel[23] = wheel[11];
            wheel[22] = wheel[10];
            wheel[21] = wheel[9];    
            break;
        case '4':
            for (i = 14; i < 24; i++)
                wheel[i] = temp[i-2];
            wheel[12] = temp[22];
            wheel[13] = temp[23];
            wheel[11] = wheel[23];
            wheel[10] = wheel[22];
            wheel[9] = wheel[21];
            break;
    }
}

int main() {

    int cases;
    int i, aux;
    char a[17], wheel[25], aux_wheel[25];
    
    memcpy(aux_wheel, solution, 25);
    hash.max = -1;
            
    backtrack(a, aux_wheel, -1, 0, 0);
    printf("%d\n", hash.max);
    
    
    qsort(hash.key, hash.max + 1, sizeof(table), compare);
    
    /*for (i = 0; i <= hash.max; i++) {
        for (aux = 0; aux < 24; aux++)
            printf("%d ", hash.key[i].configuration[aux]);
        putchar('\n');
        getchar();
    }*/
    
    scanf("%d", &cases);
    while (cases) {
    
        for (i = 0; i < 24; i++) {
            scanf("%d", &aux);
            wheel[i] = aux;
        }
        wheel[i] = '\0';
        
        if (!stringcmp(solution, wheel))
            printf("PUZZLE ALREADY SOLVED\n");
        else if ((aux = binary_search(wheel, 0, hash.max)) == -1)
            printf("NO SOLUTION WAS FOUND IN 16 STEPS\n");
        else
            printf("%s\n", hash.key[aux].solution);
        
        cases--;
    }
    
    return 0;
}

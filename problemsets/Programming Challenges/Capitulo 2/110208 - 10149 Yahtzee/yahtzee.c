/* Yahtzee */

#include <stdio.h>
#include <stdlib.h>

int table[13][5];
int score[15];
int aux_score[15];
char valids[13];
char aux_valid[13];
int aux_total;
char finished;


int num_cmp(const void *x, const void *y) {
    
    return(*(int *)x - *(int *) y);
}

int sum(int dices[]) {
    int i;
    int sum = 0;
    
    for (i = 0; i < 5; i++)
        sum += dices[i];
    return (sum);
}


/************************** Categories Functions ******************************/

/* ones, twos, threes, fours, fives, sixes */
int sums(int dices[], int option) {
    int sum, i;
    
    for (i = 0, sum = 0; i < 5; i++)
        if (dices[i] == option)
            sum += option;
            
    return (sum);
}

int chance(int dices[]) {
    int sum, i;
    
    for (i = 0, sum = 0; i < 5; i++)
            sum += dices[i];

    return (sum);
}

int three(int dices[]) {
    int i;
    
    for (i = 0; i < 3; i++)
        if ((dices[i] == dices[i+1]) && (dices[i] == dices[i+2]))
            return 1;
    return 0;
}

int four(int dices[]) {
    int i;
    
    for (i = 0; i < 2; i++)
        if ((dices[i] == dices[i+1]) && (dices[i] == dices[i+2]) && 
        (dices[i] == dices[i+3]))
            return 1;
    return(0);
}

int five(int dices[]) {
    int i;
    
    for (i = 0; i < 4; i++)
        if (dices[i] != dices[i+1])
            return (0);
    return(1);
}

int s_straight(int dices[]) {
    int i;
    char iss_straight = 1;
    
    for (i = 0; (i < 3) && (iss_straight); i++)
        if ((dices[i+1] - dices[i]) != 1)
            iss_straight = 0;
    if (iss_straight)
        return (1);
    
    for (i = 1; i < 4; i++)
        if ((dices[i+1] - dices[i]) != 1)
            return (0);
    return(1);
}

int l_straight(int dices[]) {
    int i;

    for (i = 0; i < 4; i++)
        if ((dices[i+1] - dices[i]) != 1)
            return (0);
    return(1);
}

int full(int dices[]) {

    int i;
    
    /* A three and a pair */
    for (i = 0; i < 4; i++) {
        if (i != 2)
            if (dices[i+1] != dices[i])
                break;
        if (i == 3)
            return 1;
    }
    
    /* A pair and a three */
    for (i = 0; i < 4; i++) {
        if (i != 1)
            if (dices[i+1] != dices[i])
                break;
        if (i == 3)
            return 1;
    }
    return 0;
}
/******************************************************************************/

void first_assig(int *points, char valid[]) {
    int i, cont, aux;
    int max_sum, pos;
    char modify;
    
    cont = 9;
    while(cont != -1) {
        max_sum = 100;
        for (i = 0; i < 13; i++) {
            if (valid[i]) {
                modify = 0;
                switch(cont) {
                    case 9:
                        if (five(table[i]))
                            modify = 1;
                        break;
                    case 10:
                        if (s_straight(table[i]))
                            modify = 1;
                        break;
                    case 11:
                        if (l_straight(table[i]))
                            modify = 1;
                        break;
                    case 12:
                        if (full(table[i]))
                            modify = 1;
                        break;
                }
                if (modify) {
                    aux = sum(table[i]);
                    if (aux < max_sum) {
                        max_sum = aux;
                        pos = i;
                    }
                }
            }
        }
        if (max_sum != 100) {
            valid[pos] = 0;
            if (cont == 9)
                points[cont] = 50;
            else if (cont == 10)
                points[cont] = 25;
            else if (cont == 11)
                points[cont] = 35;
            else if (cont == 12)
                points[cont] = 40;
        }
        switch (cont) {
            case 9:
                cont = 12;
                break;
            case 10:
                cont = -1;
                break;
            case 11:
                cont = 10;
                break;
            case 12:
                cont = 11;
                break;
        }
    }
}

int cont_score() {
    
    int i, total;
    
    for (i = 0, total = 0; i < 9; i++)
        if (aux_score[i] == -1)
            return (-1);
        else
            total += aux_score[i];
    return (total);
}

void find_best(int *total) {

    int i, j, sum1, aux_sum, pos, bonus;
   
    for (i = 0; i < 9; i++) {
        if (aux_score[i] == -1) {
            for (j = 0, pos = -1, sum1 = 0; j < 13; j++) {
                if (aux_valid[j]) {
                    switch (i) {
                        case 0:
                            if ((aux_sum = sums(table[j], 1)) > sum1) {
                                sum1 = aux_sum;
                                pos = j;
                            }
                            break;
                        case 1:
                            if ((aux_sum = sums(table[j], 2)) > sum1){
                                sum1 = aux_sum;
                                pos = j;
                            }
                            break;
                        case 2:
                            if ((aux_sum = sums(table[j], 3)) > sum1) {
                                sum1 = aux_sum;
                                pos = j;
                            }
                            break;
                        case 3:
                            if ((aux_sum = sums(table[j], 4)) > sum1) {
                                sum1 = aux_sum;
                                pos = j;
                            }
                            break;
                        case 4:
                            if ((aux_sum = sums(table[j], 5)) > sum1) {
                                sum1 = aux_sum;
                                pos = j;
                            }
                            break;
                        case 5:
                            if ((aux_sum = sums(table[j], 6)) > sum1) {
                                sum1 = aux_sum;
                                pos = j;
                            }
                            break;
                        case 6:
                            if ((aux_sum = sum(table[j])) > sum1) {
                                sum1 = aux_sum;
                                pos = j;
                            }
                            break;
                        case 7:
                            if (three(table[j]))
                                if ((aux_sum = sum(table[j])) > sum1) {
                                    sum1 = aux_sum;
                                    pos = j;
                                }
                            break;
                        case 8:
                            if (four(table[j]))
                                if ((aux_sum = sum(table[j])) > sum1) {
                                    sum1 = aux_sum;
                                    pos = j;
                                }
                            break;
                    }
                }
            }
            aux_score[i] = sum1;
            finished++;
            if (pos != -1)
                aux_valid[pos] = 0;
            
            if (finished == 9) {
                aux_total = cont_score();    
                for (j = 0, bonus = 0; j < 6; j++)
                    bonus += aux_score[j];
                if (bonus >= 63)
                    aux_total += 35;
                if (aux_total > *total) {
                    *total = aux_total;
                    for (j = 0; j < 9; j++)
                        score[j] = aux_score[j];
                    if (bonus >= 63)
                        score[13] = 35;
                }
            }
            else
                find_best(total);
            
            aux_score[i] = -1;
            finished--;
            if (pos != -1)
                aux_valid[pos] = 1;    
        }
    }
}


void play() {
    int i, total;
    
    for (i = 0; i < 15; i++)
        score[i] = 0;
        
    first_assig(score, valids);
    
    total = -1;
    for (i = 0; i < 13; i++) {
        if (i < 9)
            aux_score[i] = -1;
        if (valids[i])
            aux_valid[i] = 1;
        else
            aux_valid[i] = 0;
    }
    aux_score[13] = -1;
    aux_total = 0;
    finished = 0;
     
    find_best(&total);
    
    for (i = 0, total = 0; i < 14; i++)
        total += score[i];
    score[14] = total;
}

int main() {
    
    int i, j;
    
    while (1) {
    
        for (i = 0; i < 13; i++) {
            for (j = 0; j < 5; j++)
                if(scanf("%d", &table[i][j]) == EOF)
                    return 0;
            qsort(table[i], 5, sizeof(int), num_cmp);
            valids[i] = 1;
        }
        
        play();
        
        for (i = 0; i < 14; i++)
            printf("%d ", score[i]);
        printf("%d\n", score[i]);
        
    }
    
    return 0;
}

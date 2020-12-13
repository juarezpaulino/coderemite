/* Poker Hands */

#define NCARDS 52
#define NSUITS 4

#include <stdio.h>
#include <stdlib.h>

char values[] = "23456789TJQKA";
char suits[] = "CDHS";

int rank_card(char value, char suit) {
    
    int i, j;
    
    for (i = 0; i < (NCARDS / NSUITS); i++)
        if (values[i] == value)
            for (j = 0; j < NSUITS; j++)
                if (suits[j] == suit)
                    return (i * NSUITS + j);
    
    return (-1);
}


int value(int card) {
    
    return(card/NSUITS);
}

int suit(int card) {
    
    return(card%NSUITS);
}
    
int compare(const void *x, const void *y) {
    
    int a = *(int *)x;
    int b = *(int *)y;
    
    return(value(a) - value(b));
}

int isPair(int a[], int *b) {
    
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (value(a[i]) == value(a[j])) {
                *b = value(a[i]);
                return 1;
            }
    
    return 0;
}

int isTwo(int a[], int *b, int *c) {

    int i, j, cont;
    
    cont = 0;
    *b = 5000;
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (value(a[i]) != *b)
                if (value(a[i]) == value(a[j])) {
                    if (cont == 1) {
                        *c = value(a[i]);
                        return 1;
                    }
                    *b = value(a[i]);
                    cont++;
                }
    
    return 0;    
}
        
int isThree(int a[], int *b) {

    int i, j, k;
    for (i = 0; i < 3; i++)
        for (j = i + 1; j < 4; j++)
            for (k = j + 1; k < 5; k++)
                if ((value(a[i]) == value(a[j])) && (value(a[j]) == value(a[k]))) {
                    *b = value(a[i]);
                    return 1;
                }
    
    return 0;    
}

int isStraight(int a[]){
    
    int i;
    for (i = 0; i < 4; i++)
        if ((value(a[i+1]) - value(a[i])) != 1)
            return 0;
    return 1;    
}

int isFlush(int a[]) {
        
    int i;
    for (i = 0; i < 4; i++)
        if (suit(a[i+1]) != suit(a[i]))
            return 0;
    return 1;    
}

int isFull(int a[], int *b) {

    int i;
    
    /* A three and a pair */
    for (i = 0; i < 4; i++) {
        if (i != 2)
            if (value(a[i+1]) != value(a[i]))
                break;
        if (i == 3) {
            *b = value(a[0]);
            return 1;
        }
    }
    
    /* A pair and a three */
    for (i = 0; i < 4; i++) {
        if (i != 1)
            if (value(a[i+1]) != value(a[i]))
                break;
        if (i == 3) {
            *b = value(a[i]);
            return 1;
        }
    }
            
    return 0;
}

int isFour(int a[], int *b) {
    
    int i, j, k, l;
    for (i = 0; i < 2; i++)
        for (j = i + 1; j < 3; j++)
            for (k = j + 1; k < 4; k++)
                for (l = k + 1; l < 5; l++)
                    if ((value(a[i]) == value(a[j])) && (value(a[j]) == value(a[k]))
                     && (value(a[k]) == value(a[l]))) {
                        *b = value(a[i]);
                        return 1;
                    }
    
    return 0;    
}

int isStrFlush(int a[]) {

    if ((isFlush(a)) && (isStraight(a)))
        return 1;
    return 0;    
}

int play(int hands[][5]) {
    
    int score[2], b[2], c[2]; 
    int i;
    
    for (i = 0; i < 2; i++) {
        if (isStrFlush(hands[i]))
            score[i] = 9;
        else if (isFour(hands[i], &b[i]))
            score[i] = 8;
        else if (isFull(hands[i], &b[i]))
            score[i] = 7;
        else if (isFlush(hands[i]))
            score[i] = 6;
        else if (isStraight(hands[i]))
            score[i] = 5;
        else if (isThree(hands[i], &b[i]))
            score[i] = 4;
        else if (isTwo(hands[i], &b[i], &c[i]))
            score[i] = 3;
        else if (isPair(hands[i], &b[i]))
            score[i] = 2;
        else score[i] = 1;
    }
    
    if ((score[0] - score[1]) != 0)
        return (score[0] - score[1]);
    else {
        if (score[0] == 2) {
            if (b[0] != b[1])
                return(b[0] - b[1]);
            else
                for (i = 4; i >= 0; i--)
                    if (value(hands[0][i]) != value(hands[1][i]))
                        return (value(hands[0][i]) - value(hands[1][i]));
            return 0;
        }
        else if (score[0] == 3) {
            if (c[0] != c[1])
                return(c[0] - c[1]);
            else if (b[0] != b[1])
                return (b[0] - b[1]);
            else
                for (i = 4; i >= 0; i--)
                    if (i > 1)
                        if (value(hands[0][i]) != value(hands[1][i]))
                            return (value(hands[0][i]) - value(hands[1][i]));
            return 0;
        }
        else if ((score[0] == 4) || (score[0] == 7) || (score[0] == 8)) {
            if (b[0] != b[1])
                return(b[0] - b[1]);
        }
        else {
            for (i = 4; i >= 0; i--)
                if (value(hands[0][i]) != value(hands[1][i]))
                    return(value(hands[0][i]) - value(hands[1][i]));
        }    
            
    }
    return 0;    
        
}


int main() {

    int hands[2][5];
    char line[82];
    char num, suit;
    int i, j;
    
    while (fgets(line, 82, stdin)) {
        i = 0;
        j = 0;
        
        while ((line[i] != '\n') && (line[i] != '\0')) {
            while (line[i] == ' ')
                i++;
            if ((line[i] != '\n') && (line[i] != '\0')) {
                num = line[i];
                suit = line[i+1];
                i += 2;

                if (j < 5)
                    hands[1][j] = rank_card(num, suit);
                else
                    hands[0][j - 5] = rank_card(num, suit);
                j++;
            }
        }
         
        qsort(hands[0], 5, sizeof(int), compare);
        qsort(hands[1], 5, sizeof(int), compare);
          
        i = play(hands);
        if (i > 0)
            printf("White wins.\n");
        else if (i < 0)
            printf("Black wins.\n");
        else
            printf("Tie.\n");
    }
    
    return 0;
}

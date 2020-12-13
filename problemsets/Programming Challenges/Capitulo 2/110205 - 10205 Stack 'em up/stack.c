/* Stack 'em up */

#define NCARDS 52
#define NSUITS 4

#include <stdio.h>
#include <stdlib.h>

short int deck[52];
short int shuffles[100][52];

int value(int card) {
    
    return((card - 1)%(NCARDS/4));
}

int suit(int card) {
    
    return((card - 1)/(NCARDS/4));
}

void print_card(int card) {

    int num = value(card);
    int figure = suit(card);

    switch(num) {
        case 9:
            printf("Jack ");
            break;
        case 10:
            printf("Queen ");
            break;
        case 11:
            printf("King ");
            break;
        case 12:
            printf("Ace ");
            break;
        default:
            printf("%d ", num + 2);
    }
    switch(figure) {
        case 0:
            printf("of Clubs\n");
            break;
        case 1:
            printf("of Diamonds\n");
            break;
        case 2:
            printf("of Hearts\n");
            break;
        case 3:
            printf("of Spades\n");
            break;
    }            
}

void init_deck() {
    
    int i;
    for (i = 1; i <= 52; i++)
        deck[i - 1] = i;
}

int main() {

    int cases, num_shuffles, shuff;
    int i, j;
    char line[6];
    short int aux_deck[52];
    
    scanf("%d", &cases);
    while (cases) {
        
        scanf("%d", &num_shuffles);
        
        for (i = 0; i < num_shuffles; i++)
            for (j = 0; j < NCARDS; j++)
                scanf("%hd", &shuffles[i][j]);
        
        init_deck();
        
        fgets(line, 6, stdin);
        do {
            
            if(!fgets(line, 6, stdin))
                break;
            if ((*line == EOF) || (*line == '\n'))
                break;
                
            sscanf(line, "%d", &shuff);
            
            for (i = 0; i < NCARDS; i++)
                aux_deck[i] = deck[shuffles[shuff - 1][i] - 1];
            for (i = 0; i < NCARDS; i++)
                deck[i] = aux_deck[i];
            
        } while (*line != '\n');  
        
        for (i = 0; i < NCARDS; i++)
            print_card(deck[i]);
        
        if (cases > 1)
            putchar('\n');
        cases--;
    }    

    return 0;
}

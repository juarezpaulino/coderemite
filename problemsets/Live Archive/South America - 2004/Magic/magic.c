/* Magic Trick */

#include <stdio.h>

typedef struct {
    char num;
    char suit;
} card;

int n;

int num(char ch) {
    
    if (ch == 'T') return(10);
    else if (ch == 'J') return(11);
    else if (ch == 'Q') return(12);
    else if (ch == 'K') return(13);
    else return(ch-'0');
}

int value(card *a) {
    
    int s;
    
    if (a->suit == 'H') s = 0;
    else if (a->suit == 'C') s = 13;
    else if (a->suit == 'D') s = 26;
    else s = 39;
    
    s += num(a->num);
    
    return (s);
}


int main() {
    
    int i, j;
    card c[4], h;
    int c1, c2, c3;
    char ch;
    int d;
    int aux;
    
    scanf("%d%*c", &n);
    for (i = 0; i < n; i++) {
        
        for (j = 0; j < 4; j++) {
            ch = getchar(); c[j].num = ch;
            ch = getchar(); c[j].suit = ch;
            getchar();
        }
        h.suit = c[0].suit;
        c1 = value(&c[1]); c2 = value(&c[2]); c3 = value(&c[3]);
        if ((c1 < c2) && (c1 < c3)) {
            if (c2 < c3) d = 1;
            else d = 2;
        }
        else if (c2 < c3) {
            if (c1 < c3) d = 3;
            else d = 5;
        }
        else {
            if (c1 < c2) d = 4;
            else d = 6;
        }
        
        aux = (num(c[0].num)+d)%13;
        if (aux == 0) h.num = 'K';
        else if (aux == 10) h.num = 'T';
        else if (aux == 11) h.num = 'J';
        else if (aux == 12) h.num = 'Q';
        else h.num = '0'+aux;
        
        printf("%c%c\n", h.num, h.suit);
    }
    
    return (0);
}

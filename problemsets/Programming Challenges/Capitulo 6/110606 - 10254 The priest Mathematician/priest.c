/* The priest mathematician */

#include <stdio.h>

#define MAXDIGITS 46

#define PLUS 1
#define MINUS -1

typedef struct {
    char digits[MAXDIGITS];
    int signbit;
    int lastdigit;
} bignum;

void print_bignum(bignum *n) {
    
    int i;
    
    if (n -> signbit == MINUS) putchar('-');
    for (i = n -> lastdigit; i >= 0; i--)
        printf("%c", '0' + n -> digits[i]);
    putchar('\n');
}

int max(int a, int b) {
    if (a > b)
        return  a;
    else
        return b;
} 

void initialize_bignum(bignum *n) {
    
    int i;
    for (i = 0; i < MAXDIGITS; i++)
        n -> digits[i] = 0;
    n -> signbit = PLUS;
    n -> lastdigit = 0;
}

void zero_justify(bignum *n) {
    
    while ((n -> lastdigit > 0) && (n -> digits[n -> lastdigit] == 0))
        n -> lastdigit--;
    
    if ((n -> lastdigit == 0) && (n -> digits[0] == 0))
        n -> signbit = PLUS;
}

void add_bignum(bignum *a, bignum *b, bignum *c) {
    
    int carry;
    int i;
    
    initialize_bignum(c);
    
    if (a -> signbit == b -> signbit) c -> signbit = a -> signbit;
    
    c -> lastdigit = max(a -> lastdigit, b -> lastdigit) + 1;
    carry = 0;
    
    for (i = 0; i <= (c -> lastdigit); i++) {
        c -> digits[i] = (char) (carry + a -> digits[i] + b -> digits[i]) % 10;
        carry = (carry + a -> digits[i] + b -> digits[i]) / 10;
    }
    
    zero_justify(c);
}

void int_to_bignum(int s, bignum *n) {
    
    int i;
    int t;
    
    for (i = 0; i < MAXDIGITS; i++) n -> digits[i] = (char) 0;
    
    n -> lastdigit = -1;
    t = s;
    
    while (t > 0) {
        n -> lastdigit++;
        n -> digits[n -> lastdigit] = (t % 10);
        t /= 10;
    }
    
    if (s == 0) n -> lastdigit = 0;
    if (s < 0)
        n -> signbit = MINUS;
    else
        n -> signbit = PLUS;
}

bignum transfers[10000];

void build_transfers() {

    int i, j, cont;
    bignum *power2 = (bignum *) malloc(sizeof(bignum));
    bignum *aux = (bignum *) malloc(sizeof(bignum));
    
    int_to_bignum(1, &transfers[0]);
    int_to_bignum(3, &transfers[1]);
    int_to_bignum(5, &transfers[2]);
    int_to_bignum(9, &transfers[3]);
    int_to_bignum(13, &transfers[4]);
    int_to_bignum(17, &transfers[5]);
    int_to_bignum(8, power2);
    *aux = *power2;
    for (i = 6, cont = 4, j = 0; i < 10000; i++, j++) {
        if (j >= cont) {
            j = 0;
            add_bignum(power2, power2, aux);
            *power2 = *aux;
            cont++;
        }
        add_bignum(aux, &transfers[i-1], &transfers[i]);
    }
    
    free(power2);
    free(aux);
}


int main() {
    
    int n;
    
    build_transfers();
    while (scanf("%d", &n) != EOF)
        if (n == 0)
            printf("0\n");
        else
            print_bignum(&transfers[n-1]);
    
    return 0;
}

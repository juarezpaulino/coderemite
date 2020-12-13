/* Counting */

#include <stdio.h>
#include <stdlib.h>


#define MAXDIGITS 410

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

int compare_bignum(bignum *a, bignum *b) {

    int i;
    
    if ((a -> signbit == MINUS) && (b -> signbit == PLUS)) return(PLUS);
    if ((a -> signbit == PLUS) && (b -> signbit == MINUS)) return(MINUS);
    
    if (b -> lastdigit > a -> lastdigit) return (PLUS * a -> signbit);
    if (a -> lastdigit > b -> lastdigit) return (MINUS * a -> signbit);
    
    for (i = a -> lastdigit; i >= 0; i--) {
        if (a -> digits[i] > b -> digits[i])
            return (MINUS * a -> signbit);
        if (b -> digits[i] > a -> digits[i])
            return (PLUS * a -> signbit);
    }
    
    return(0);
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

void digit_shift(bignum *n, int d) {
    
    int i;
    
    if ((n -> lastdigit == 0) && (n -> digits[0] == 0)) return;
    
    for (i = n -> lastdigit; i >= 0; i--)
        n -> digits[i+d] = n -> digits[i];
    
    for (i = 0; i < d; i++)
        n -> digits[i] = 0;

    n -> lastdigit = n -> lastdigit + d;
}

void multiply_bignum(bignum *a, bignum *b, bignum *c) {

    bignum *row = (bignum *) malloc(sizeof(bignum));
    bignum *tmp = (bignum *) malloc(sizeof(bignum));
    
    int i, j;
    
    initialize_bignum(c);
    
    *row = *a;
    
    for (i = 0; i <= b -> lastdigit; i++) {
        for (j = 1; j <= b -> digits[i]; j++) {
            add_bignum(c, row, tmp);
            *c = *tmp;
        }
        digit_shift(row, 1);
    }
 
    c -> signbit = a -> signbit * b -> signbit;
    
    zero_justify(c);
    
    free(row);
    free(tmp);
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

bignum sums[1000];

void build_sums() {

    int i;
    bignum *aux = (bignum *) malloc(sizeof(bignum));
    bignum *aux2 = (bignum *) malloc(sizeof(bignum));
    
    int_to_bignum(2, &sums[0]);
    int_to_bignum(5, &sums[1]);
    int_to_bignum(13, &sums[2]);
    
    initialize_bignum(aux);
    initialize_bignum(aux2);
    for (i = 3; i < 1000; i++) {
        multiply_bignum(&sums[i - 1], &sums[0], aux);
        add_bignum(aux, &sums[i - 2], aux2);
        add_bignum(aux2, &sums[i - 3], &sums[i]);
    }

    free(aux);
    free(aux2);
}

int main() {

    int n;

    build_sums();
    while (scanf("%d", &n) != EOF)
        print_bignum(&sums[n-1]);
    
    return 0;
}

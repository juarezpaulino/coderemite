/* How many pieces of land? */

#include <stdio.h>
#include <stdlib.h>

#define MAXDIGITS 60

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

void subtract_bignum(bignum *a, bignum *b, bignum *c) {
    
    int borrow, carry;
    int v; 
    int i;
    
    initialize_bignum(c);
    
    if ((a -> signbit == MINUS) || (b -> signbit == MINUS)) {
        b -> signbit = -1 * b -> signbit;
    
        if (a -> signbit == b -> signbit) c -> signbit = a -> signbit;
        else {
            if (a -> signbit == MINUS) {
                a -> signbit = PLUS;
                subtract_bignum(b, a, c);
                a -> signbit = MINUS;
            }
            else {
                b -> signbit = PLUS;
                subtract_bignum(a, b, c);
                b -> signbit = MINUS;
            }
            return;
        }
        
        
        c -> lastdigit = max(a -> lastdigit, b -> lastdigit) + 1;
        carry = 0;
        
        for (i = 0; i <= (c -> lastdigit); i++) {
            c -> digits[i] = (char) (carry + a -> digits[i] + b -> digits[i]) % 10;
            carry = (carry + a -> digits[i] + b -> digits[i]) / 10;
        }
        
        zero_justify(c);
        
        b -> signbit = -1 * b -> signbit;
        return;
    }
    
    if (compare_bignum(a, b) == PLUS) {
        subtract_bignum(b, a, c);
        c -> signbit = MINUS;
        return;
    }
    
    c -> lastdigit = max(a -> lastdigit, b -> lastdigit);
    borrow = 0;
    
    for (i = 0; i <= (c -> lastdigit); i++) {
        v = (a -> digits[i] - borrow - b -> digits[i]);
        if (a -> digits[i] > 0)
            borrow = 0;
        if (v < 0) {
            v = v + 10;
            borrow = 1;
        }
        
        c -> digits[i] = (char) v % 10;
    }
    
    zero_justify(c);
}

void add_bignum(bignum *a, bignum *b, bignum *c) {
    
    int carry;
    int i;
    
    initialize_bignum(c);
    
    if (a -> signbit == b -> signbit) c -> signbit = a -> signbit;
    else {
        if (a -> signbit == MINUS) {
            a -> signbit = PLUS;
            subtract_bignum(b, a, c);
            a -> signbit = MINUS;
        }
        else {
            b -> signbit = PLUS;
            subtract_bignum(a, b, c);
            b -> signbit = MINUS;
        }
        return;
    }
    
    
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


void divide_bignum(bignum *a, bignum *b, bignum *c) {
    
    bignum *row = (bignum *) malloc(sizeof(bignum));
    bignum *tmp = (bignum *) malloc(sizeof(bignum));
    
    int asign, bsign;
    int i;
    
    initialize_bignum(c);
    
    asign = a -> signbit;
    bsign = b -> signbit;
    
    a -> signbit = PLUS;
    b -> signbit = PLUS;
    
    initialize_bignum(row);
    initialize_bignum(tmp);
    
    c -> lastdigit = a -> lastdigit;
    
    for (i = a -> lastdigit; i >= 0; i--) {
        digit_shift(row, 1);
        row -> digits[0] = a -> digits[i];
        c -> digits[i] = 0;
        zero_justify(row);
        while (compare_bignum(row, b) != PLUS) {
            c -> digits[i]++;
            subtract_bignum(row, b, tmp);
            *row = *tmp;
        }
    }
        
    zero_justify(c);
    
    a -> signbit = asign;
    b -> signbit = bsign;
    
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

bignum one, two, three, twelve, twenty_four;

void recurrence(bignum *n, bignum *p) {
    
    bignum *aux = (bignum *) malloc(sizeof(bignum));
    bignum *subt = (bignum *) malloc(sizeof(bignum));
    bignum *subt2 = (bignum *) malloc(sizeof(bignum));
    bignum *mult = (bignum *) malloc(sizeof(bignum));
    bignum *mult2 = (bignum *) malloc(sizeof(bignum));
    
    initialize_bignum(subt);
    subtract_bignum(n, &two, subt);
    
    /*printf("Subt (n-2): ");
    print_bignum(subt);*/
    
    initialize_bignum(subt2);
    subtract_bignum(n, &three, subt2);
    
    /*printf("Subt2 (n-3): ");
    print_bignum(subt2);*/
    
    initialize_bignum(mult);
    multiply_bignum(subt, subt2, mult);
    
    /*printf("Mult (n-2)(n-3): ");
    print_bignum(mult);*/
    
    initialize_bignum(aux);
    add_bignum(&twelve, mult, aux);
    
    /*printf("Add 6 + x: ");
    print_bignum(aux);*/
    
    initialize_bignum(subt);
    subtract_bignum(n, &one, subt);
    
    /*printf("Subt (n-1): ");
    print_bignum(subt);*/
    
    initialize_bignum(mult);
    multiply_bignum(aux, subt, mult);
    
    /*printf("Mult (n-1)(x): ");
    print_bignum(mult);*/
    
    initialize_bignum(mult2);
    multiply_bignum(n, mult, mult2);
    
    /*printf("Mult (n)(x): ");
    print_bignum(mult2);*/
    
    initialize_bignum(aux);
    divide_bignum(mult2, &twenty_four, aux);
    
    /*printf("Subt (x)/12: ");
    print_bignum(aux);*/
    
    add_bignum(&one, aux, p);
    
    /*printf("add (1+x): ");
    print_bignum(p);*/
    
    free(aux);
    free(subt);
    free(subt2);
    free(mult);
    free(mult2);
}

int main() {

    int cases, points;
    bignum pieces, big_points;
    
    int_to_bignum(1, &one);
    int_to_bignum(2, &two);
    int_to_bignum(3, &three);
    int_to_bignum(12, &twelve);
    int_to_bignum(24, &twenty_four);
    
    scanf("%d", &cases);
    while (cases) {
        
        scanf("%d", &points);
        
        int_to_bignum(points, &big_points);
        recurrence(&big_points, &pieces);
        print_bignum(&pieces);
        
        cases--;   
    }
    
    return 0;
}

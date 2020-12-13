/* How many fibs? */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXDIGITS 1500

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

bignum fibo[551], t1, t2;
int range;

void build_fibo() {

    int i;

    initialize_bignum(&fibo[0]);
    fibo[0].digits[0] = 1;
    fibo[0].signbit = PLUS;
    initialize_bignum(&fibo[1]);
    fibo[1].digits[0] = 2;
    fibo[1].signbit = PLUS;
    
    for (i = 2; i <= 550; i++)
        add_bignum(&fibo[i-2], &fibo[i-1], &fibo[i]);
    
}

void check(int min, int max) {

    int i;
    for (i = min, range = 0; i <= max; i++)
        if ((compare_bignum(&fibo[i], &t1) != 1) && (compare_bignum(&fibo[i], &t2) != -1))
            range++;
}

int main() {
    
    double fib1, fib2;
    int max, min, i;
    char a[1500], b[1500];
    
    build_fibo();
    while (scanf("%s %s", a, b)) {

        if (!strcmp(a, "0") && !strcmp(b, "0"))
            break;
        
        sscanf(a, "%lf", &fib1);
        sscanf(b, "%lf", &fib2);
        
        t1.lastdigit = strlen(a) - 1;
        for (i = 0; i <= t1.lastdigit; i++)
            t1.digits[t1.lastdigit - i] = a[i] - '0';
        t1.signbit = PLUS;
        
        t2.lastdigit = strlen(b) - 1;
        for (i = 0; i <= t2.lastdigit; i++)
            t2.digits[t2.lastdigit - i] = b[i] - '0';
        t2.signbit = PLUS;
        
        if (fib1 > 0.05)
            min = floor((log(pow(5, 0.5) * fib1)/log((1 + pow(5, 0.5))/2)) - 2);
        else
            min = 0;
        if (min < 0)
            min++;
        max = ceil((log(pow(5, 0.5) * fib2)/log((1 + pow(5, 0.5))/2)) - 1);
        
        check(min, max);
        
        printf("%d\n", range);
    }

    return 0;   
}

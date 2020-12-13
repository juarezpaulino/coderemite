/* Distinct Subsequences */

#include <stdio.h>
#include <string.h>

#define MAXX 10002
#define MAXZ 102
#define MAXDIGITS 103

typedef struct {
    char digits[MAXDIGITS];
    int lastdigit;
} bignum;

bignum m[2][MAXX];

void print_bignum(bignum *n) {
    
    int i;
    
    for (i = n->lastdigit; i >= 0; i--)
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
    n -> lastdigit = 0;
}

void zero_justify(bignum *n) {
    
    while ((n -> lastdigit > 0) && (n -> digits[n -> lastdigit] == 0))
        n -> lastdigit--;
}

void add_bignum(bignum *a, bignum *b, bignum *c) {
    
    int carry;
    int i;
    
    initialize_bignum(c);
    
    c -> lastdigit = max(a -> lastdigit, b -> lastdigit) + 1;
    carry = 0;
    
    for (i = 0; i <= (c -> lastdigit); i++) {
        c -> digits[i] = (char) (carry + a->digits[i] + b->digits[i]) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }
    
    zero_justify(c);
}

void set_bignum(unsigned s, bignum *n) {
    
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
}

void copy_bignum(bignum *dest,  bignum *src) {

    int i;

    dest -> lastdigit = src -> lastdigit;
    for (i = 0; i < MAXDIGITS; i++)
        dest -> digits[i] = src -> digits[i];    
}

void count_sequences(char *x, char *z) {
    
    int length_x = strlen(x);
    int length_z = strlen(z);
    int i, j, k, l;
    unsigned count;
    
    if (x[0] == z[0]) {
        set_bignum(1, &m[0][0]);
        count = 1;
    }
    else {
        initialize_bignum(&m[0][0]);
        count = 0;
    }
    for (i = 1; i < length_x; i++) {
        if (x[i] == z[0]) {
            count++;
            set_bignum(count, &m[0][i]);
        }
        else
            copy_bignum(&m[0][i], &m[0][i-1]);
    }
    k = 1;
    for (j = 1; j < length_z; j++) {
        set_bignum(0, &m[k][j-1]);
        for (i = j; i < length_x; i++)
            if (x[i] == z[j])
                add_bignum(&m[k^1][i-1], &m[k][i-1], &m[k][i]);
            else
                copy_bignum(&m[k][i], &m[k][i-1]);
        k = k ^ 1;
    }

    print_bignum(&m[k^1][length_x-1]);
}


int main() {
    
    char x[MAXX];
    char z[MAXZ];
    int cases;
    
    scanf("%d",  &cases);
    while (cases) {
    
        scanf("%s", x);
        scanf("%s", z);
        count_sequences(x, z);
            
        cases--;
    }

    return 0;
}

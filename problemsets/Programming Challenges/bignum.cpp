/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Bignum Class */

#include <cstdio>

#define MAXDIGITS 500

#define PLUS 1
#define MINUS -1

#define max(a, b) ((a)>(b)?(a):(b))

class bignum {
    char dig[MAXDIGITS];
    int last;
    char sign;
public:
    
    bignum(int num = 0) { reset(num); }
    void reset(int num);
    
    void zero_justify();
    void digit_shift(int d);
    int compare(bignum b);
    
    void print();
    
    bignum abs() { bignum b = *this; b.sign = PLUS; return (b); }
    
    void operator=(int num) { reset(num); }
    
    bool operator==(bignum b) { return (!compare(b)); }
    bool operator!=(bignum b) { char t = compare(b); return (t != 0); }
    bool operator>(bignum b) { return (compare(b)==MINUS); }
    bool operator>=(bignum b) { char t = compare(b); return (t <= 0); }
    bool operator<(bignum b) { return (compare(b)==PLUS); }
    bool operator<=(bignum b) { char t = compare(b); return (t >= 0); }
    
    bignum operator+(bignum b);
    friend bignum operator+(bignum a, int num) { bignum b(num); return(a + b); }
    friend bignum operator+(int num, bignum a) { bignum b(num); return(b + a); }
    bignum operator-(bignum b);
    friend bignum operator-(bignum a, int num) { bignum b(num); return(a - b); }
    friend bignum operator-(int num, bignum a) { bignum b(num); return(b - a); }
    bignum operator*(bignum b);
    friend bignum operator*(bignum a, int num) { bignum b(num); return(a * b); }
    friend bignum operator*(int num, bignum a) { bignum b(num); return(b * a); }
    bignum operator/(bignum b);
    friend bignum operator/(bignum a, int num) { bignum b(num); return(a / b); }
    friend bignum operator/(int num, bignum a) { bignum b(num); return(b / a); }
    bignum operator%(bignum b);
    friend bignum operator%(bignum a, int num) { bignum b(num); return(a % b); }
    friend bignum operator%(int num, bignum a) { bignum b(num); return(b % a); }
    
    bignum pwr(int pw);
    bignum root(int n);
};

void bignum::zero_justify() {
    
    while ((last > 0) && (dig[last] == 0))
        last--;
    if ((last == 0) && (dig[0] == 0))
        sign = PLUS;
}

void bignum::digit_shift(int d) {
    
    int i;
    
    if ((last == 0) && (dig[0] == 0)) return;
      
    for (i = last; i >= 0; i--) dig[i+d] = dig[i];
    
    for (i = 0; i < d; i++) dig[i] = 0;

    last = last + d;
}

void bignum::reset(int num) {
    
    int i;
    
    if (num == 0) {
        for (i = 0; i < MAXDIGITS; i++) dig[i] = 0;
        sign = PLUS;
        last = 0;
    }
    else {
        if (num < 0) { sign = MINUS; num *= -1; }
        else sign = PLUS;
        
        last = -1;
        while (num > 0) {
            last++;
            dig[last] = num%10;
            num /= 10;
        }
        for (i = last+1; i < MAXDIGITS; i++) dig[i] = 0;
    }
}

int bignum::compare(bignum b) {
    
    int i;
    
    if ((sign == MINUS) && (b.sign == PLUS)) return(PLUS);
    if ((sign == PLUS) && (b.sign == MINUS)) return(MINUS);
    
    if (b.last > last) return (PLUS * sign);
    if (last > b.last) return (MINUS * sign);
    
    for (i = last; i >= 0; i--) {
        if (dig[i] > b.dig[i])
            return (MINUS * sign);
        if (b.dig[i] > dig[i])
            return (PLUS * sign);
    }
    
    return(0);   
}

void bignum::print() {
    
    int i;
    
    if (sign == MINUS) putchar('-');
    for (i = last; i >= 0; i--)
        printf("%c", '0' + dig[i]);
    putchar('\n');   
}

bignum bignum::operator+(bignum b) {
    
    bignum c;
    int carry;
    int i;
    
    if (sign == b.sign) c.sign = sign;
    else {
        if (sign == MINUS) {
            sign = PLUS;
            c = b - *this;
            sign = MINUS;
        }
        else {
            b.sign = PLUS;
            c = *this - b;
            b.sign = MINUS;
        }
        return (c);
    }
    
    c.last = max(last, b.last) + 1;
    carry = 0;
    
    for (i = 0; i <= (c . last); i++) {
        c.dig[i] = (carry + dig[i] + b.dig[i]) % 10;
        carry = (carry + dig[i] + b.dig[i]) / 10;
    }
    c.zero_justify();
    
    return (c);
}

bignum bignum::operator-(bignum b) {
    
    bignum c;
    int borrow;
    int v; 
    int i;
    
    if ((sign == MINUS) || (b.sign == MINUS)) { 
        b.sign = MINUS * b.sign;
        c = *this + b;
        b.sign = MINUS * b.sign;
        return (c);
    }
    if (compare(b) == PLUS) {
        c = b - *this;
        c.sign = MINUS;
        return (c);
    }
    
    c.last = max(last, b.last);
    borrow = 0;
    
    for (i = 0; i <= c.last; i++) {
        v = (dig[i] - borrow - b.dig[i]);
        if (dig[i] > 0) borrow = 0;
        if (v < 0) {
            v = v + 10;
            borrow = 1;
        }
        c.dig[i] = v % 10;
    }
    c.zero_justify();
    
    return (c);
}

bignum bignum::operator*(bignum b) {

    bignum c;
    bignum *row = new bignum;
    int i, j;
    
    *row = *this;
    
    for (i = 0; i <= b.last; i++) {
        for (j = 1; j <= b.dig[i]; j++)
            c = c + *row;
        row->digit_shift(1);
    }
    c.sign = sign * b.sign;
    c.zero_justify();
    
    delete row;
    
    return (c);
}

bignum bignum::operator/(bignum b) {
    
    bignum c;
    bignum *row = new bignum;
    int asign;
    int i;
    
    c.sign = sign * b.sign;
    
    asign = sign;
    sign = PLUS;
    b.sign = PLUS;
    
    c.last = last;
    
    for (i = last; i >= 0; i--) {
        row->digit_shift(1);
        row->dig[0] = dig[i];
        c.dig[i] = 0;
        row->zero_justify();
        while (row->compare(b) != PLUS) {
            c.dig[i]++;
            *row = *row - b;
        }
    }
    c.zero_justify();
    
    sign = asign;
    
    delete row;
    
    return (c);    
}

bignum bignum::operator%(bignum b) {
    
    bignum rem;
    int asign;
    int i;
    
    rem.sign = sign;
    
    asign = sign;
    sign = PLUS;
    b.sign = PLUS;
    
    for (i = last; i >= 0; i--) {
        rem.digit_shift(1);
        rem.dig[0] = dig[i];
        rem.zero_justify();
        while (rem.compare(b) != PLUS)
            rem = rem - b;
    }
    
    sign = asign;
    
    return (rem);    
}

bignum bignum::pwr(int pw) {

    if (pw == 0)
        return (1);
    
    if (pw%2)
        return (this->pwr(pw-1) * *this);
    else {
        bignum tmp;    
        tmp = this->pwr(pw/2);
        return (tmp*tmp);
    }
}

bignum bignum::root(int n) {

    int i;
    int num;
    bignum x;
    bignum *tmp = new bignum;
    bignum *aux = new bignum;
    
    if (last+1 < n) {
        tmp->dig[0] = dig[last];
        tmp->last = 0;
    }
    else {
        num = (last+1)/n;
        for (i = 0; i < num; i++)
            tmp->dig[i] = dig[last-(num-1)+i];
        tmp->last = num-1;
    }
    
    do {
        *aux = x;
        x = *tmp;
        *tmp = ((x*(n-1))/n) + (*this/(x.pwr(n-1)*n));
        if ((((x*(n-1))%n).dig[0]) != 0)
            *tmp = *tmp+1;
        if (tmp->compare(*aux) == 0) {
            if (tmp->compare(x) == PLUS)
                x = *tmp;
            break;
        }       
    } while (x.compare(*tmp) != 0);
    x.sign = sign;
    
    delete aux;
    delete tmp;
    
    return (x);
}


int main() {
    
    bignum a(80), b(1000);
    
    (a + 7).print();
    (7 + a).print();
    
    (7%b).print();
    
    (a/b).print();
    (a*b).print();
    b.print();
    
    a = 144;
    (a.root(2)).print();
    (a.pwr(15)).print();
    
    getchar();
    
    return 0;
}

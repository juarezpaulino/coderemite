/* Jacquard Circuits */

#include <cstdio>
#include <cstdlib>

#define MAXDIGITS 23

#define PLUS 1
#define MINUS -1

#define max(a, b) ((a)>(b)?a:b)

class bignum {
    char dig[MAXDIGITS];
    int last;
    char sign;
public:

    bignum(long long num = 0) { reset(num); }
    void reset(long long num);

    void zero_justify();
    void digit_shift(int d);
    int compare(bignum b);

    void print();

    void abs() { sign = PLUS; }

    void operator=(long long num) { reset(num); }

    bool operator==(bignum b) { return(!compare(b)); }
    bool operator!=(bignum b) { char t = compare(b); return(t != 0); }
    bool operator>(bignum b) { return(compare(b)==MINUS); }
    bool operator>=(bignum b) { char t = compare(b); return (t <= 0); }
    bool operator<(bignum b) { return (compare(b)==PLUS); }
    bool operator<=(bignum b) { char t = compare(b); return (t >= 0); }

    bignum operator+(bignum b);
    friend bignum operator+(bignum a, long long num) { bignum b(num); return(a + b); }
    friend bignum operator+(long long num, bignum a) { bignum b(num); return(b + a); }
    bignum operator-(bignum b);
    friend bignum operator-(bignum a, long long num) { bignum b(num); return(a - b); }
    friend bignum operator-(long long num, bignum a) { bignum b(num); return(b - a); }
    bignum operator*(bignum b);
    friend bignum operator*(bignum a, long long num) { bignum b(num); return(a * b); }
    friend bignum operator*(long long num, bignum a) { bignum b(num); return(b * a); }
    bignum operator/(bignum b);
    friend bignum operator/(bignum a, long long num) { bignum b(num); return(a / b); }
    friend bignum operator/(long long num, bignum a) { bignum b(num); return(b / a); }
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

void bignum::reset(long long num) {

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
    //putchar('\n');
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


typedef struct {
    long long x, y;
} point;

point p[1001];
int np;
int N;
long long M;

bool colinear(point &p0, point &p1, point &p2) {

    return ((p1.x-p0.x) * (p2.y-p0.y) == (p1.y - p0.y) * (p2.x - p0.x));
}

long long GCD(long long a, long long b) {

    if (b > a) return GCD(b, a);
    if (b == 0) return (a);
    else return GCD(b, a%b);
}


int main() {

    int x, y;
    int xm, ym;
    int m;
    point a, b, c;
    bignum Ao;
    long long ro, aux, aux2;
    bignum Im;
    int cases;
    int i, j;

    cases = 1;
    while (scanf("%d %d", &N, &m)) {

        if ((N == 0) && (m == 0))
            break;

        M = m;
        xm = 1000000000;
        ym = xm;
        scanf("%d %d", &x, &y);
        a.x = x; a.y = y;
        scanf("%d %d", &x, &y);
        b.x = x; b.y = y;
        p[0] = a;
        np = 1;
        for (i = 2; i < N; i++) {
            scanf("%d %d", &x, &y);
            c.x = x; c.y = y;
            if (!colinear(a, b, c)) {
                p[np++] = b;
                if (b.x < xm) xm = b.x;
                if (b.y < ym) ym = b.y;
                a = b;
            }
            b = c;
        }
        if (!colinear(a, b, p[0])) {
            p[np++] = b;
            if (b.x < xm) xm = b.x;
            if (b.y < ym) ym = b.y;
        }
        if (colinear(p[np-1], p[0], p[1])) {
            p[0] = p[np-1];
            np--;
        }
        else {
            if (p[0].x < xm) xm = p[0].x;
            if (p[0].y < ym) ym = p[0].y;
        }

        for (i = 0; i < np; i++) {
            p[i].x = p[i].x - xm;
            p[i].y = p[i].y - ym;
        }

        xm = GCD(p[0].x, p[0].y);
        for (i = 0; (i < np) && (xm != 1); i++) {
            xm = GCD(xm, p[i].x);
            if (xm == 1) break;
            xm = GCD(xm, p[i].y);
        }
        if (xm != 1)
            for (i = 0; i < np; i++) {
                p[i].x = p[i].x / xm;
                p[i].y = p[i].y / xm;
            }

        aux = 0;
        ro = 0;
        for (i = 0; i < np; i++) {
            j = (i+1)%np;
            aux = aux + (p[j].x*p[i].y - p[i].x*p[j].y);
            ro += GCD(labs((p[j].x-p[i].x)), labs((p[j].y-p[i].y)));
        }
        Ao = aux;
        Ao.abs();

        aux = (M*(M+1))/2;
        aux2 = (2*M)+1;
        Im = (((Ao*((aux*aux2)/3))-(ro*aux)) / 2) + M;

        printf("Case %d: ", cases);
        Im.print();
        putchar('\n');
        cases++;
    }

    return 0;
}

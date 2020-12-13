/* The Blocks Problem */

#include <stdio.h>

#define MAXBLOCKS 26

typedef struct {
    int b[MAXBLOCKS];
    int top;
} stack;

void push(stack *s, int x) {
    
    s -> b[s->top] = x;
    s->top++;
}

int pop(stack *s) {

    s->top--;
    return (s->b[s->top]);    
}

int blocks[MAXBLOCKS];
stack s[MAXBLOCKS];

void moveonto(stack s[], int x, int y) {
    
    int aux;
    
    while (1) {
        aux = pop(&s[blocks[x]]);
        if (aux == x)
            break;
        else {
            blocks[aux] = aux;
            push(&s[aux], aux);
        }
    }
    
    while (1) {
        aux = pop(&s[blocks[y]]);
        if (aux == y) {
            push(&s[blocks[y]], y);
            push(&s[blocks[y]], x);
            blocks[x] = blocks[y];
            break;
        }
        else {
            blocks[aux] = aux;
            push(&s[aux], aux);
        }
    }
}

void moveover(stack s[], int x, int y) {
    
    int aux;
    
    while (1) {
        aux = pop(&s[blocks[x]]);
        if (aux == x)
            break;
        else {
            blocks[aux] = aux;
            push(&s[aux], aux);
        }
    }
    
    push(&s[blocks[y]], x);
    blocks[x] = blocks[y];
}

void pileonto(stack s[], int x, int y) {
    
    stack p;
    int aux, num;
    
    p.top = 0;
    while (1) {
        aux = pop(&s[blocks[x]]);
        push(&p, aux);
        if (aux == x)
            break;
    }
    
    while (1) {
        aux = pop(&s[blocks[y]]);
        if (aux == y) {
            push(&s[blocks[y]], y);
            while (p.top > 0) {
                num = pop(&p);
                push(&s[blocks[y]], num);
                blocks[num] = blocks[y];
            }
            break;
        }
        else {
            blocks[aux] = aux;
            push(&s[aux], aux);
        }
    }
}

void pileover(stack s[], int x, int y) {

    stack p;
    int aux;
    
    p.top = 0;
    while (1) {
        aux = pop(&s[blocks[x]]);
        push(&p, aux);
        if (aux == x)
            break;
    }
    
    while (p.top > 0) {
        aux = pop(&p);
        push(&s[blocks[y]], aux);
        blocks[aux] = blocks[y];
    }
}

void print_stack(stack *s) {

    int aux;

    if (s->top == 1)
        printf(" %d", pop(s));
    else {
        aux = pop(s);
        print_stack(s);
        printf(" %d", aux);
    }   
}


int main() {
    
    int n;
    char c[5], p[5];
    int x, y;
    int i;
    
    scanf("%d%*c", &n);
    for (i = 0; i < n; i++) {
        blocks[i] = i;
        s[i].top = 0;
        push(&s[i], i);
    }
    while (1) {
        scanf("%s", c);
        if (*c == 'q')
            break;
        
        scanf(" %d %s %d%*c", &x, p, &y);
        if ((x != y) && (blocks[x] != blocks[y])) {    
            if (*c == 'm') {
                if (p[1] == 'n')
                    moveonto(s, x, y);
                else
                    moveover(s, x, y);
            }
            else {
                if (p[1] == 'n')
                    pileonto(s, x,  y);
                else
                    pileover(s, x, y);
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        printf("%d:", i);
        if (s[i].top <= 0)
            putchar('\n');
        else {
            print_stack(&s[i]);
            putchar('\n');
        }
    }
    
    return 0;
}

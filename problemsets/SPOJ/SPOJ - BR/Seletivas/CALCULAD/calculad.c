#include <stdio.h>

double mem[30];
int pos;
char str[2000];

double expr();

double fator() {
    double x;
    if (str[pos]>='0' && str[pos]<='9') {
        x = 0.; while (str[pos]>='0' && str[pos]<='9') { x*=10.; x+=str[pos++]-'0'; }
    }
    else if (str[pos]>='a' && str[pos]<='z') { x = mem[str[pos]-'a']; pos++; }
    else if (str[pos]=='(') { pos++; x = expr(); pos++; }
    else if (str[pos]=='-') { pos++; x = -fator(); }
    return x;
}

double termo() {
    double x, y; char op;
    x = fator();
    while (str[pos]=='*'||str[pos]=='/') {
        op = str[pos++]; y = fator();
        if (op=='*') x*=y; else x/=y;
    }
    return x;
}

double expr() {
    double x, y; char op;
    x = termo();
    while (str[pos]=='+'||str[pos]=='-') {
        op = str[pos++]; y = termo();
        if (op=='+') x+=y; else x-=y;
    }
    return x;    
}


int main() {
    
    while (gets(str)) {
        if (!*str) continue;
        if (str[1]=='=') { pos = 2; mem[*str-'a'] = expr(); }
        else { pos = 0; printf("%.2lf\n", expr()); }
    }
    
    return 0;
}

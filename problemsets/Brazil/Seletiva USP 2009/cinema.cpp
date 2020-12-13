/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema A - cinema.cpp
 * 
 * Técnica: Matematica combinacao / aritmetica modular
 *
 * Entrada: n cadeiras, m casais
 * Saida: Dispor os m casais nas n cadeiras sem que nenhum casal fique afastado
 *
 * Solucao: Imagine uma solução ótima que disponha os casais:
 * - veja que temos um fator 2^m que eh a forma de trocar um casal em suas
 * cadeiras (homem, mulher), (mulher, homem)
 * - Temos um fator m! que indica que podemos permutar a ordem dos casais
 * em uma solução ótima. (__1_2_3_4) ou (__2_1_3_4) ou ...
 *
 * Resta contar as formas de dispor os espaços vagos entre os casais.
 * Imagine que cada casal represente um bloco, temos de dispor n-m*2
 * (quantidade de espacos vazios) entre n-m*2 + m (espaços vazios mais blocos 
 * de casais), ou seja:
 * ( n-m*2 + m)     =    (n-m)
 * ( n-m*2    )          ( m )
 *
 * Conta final:     2^m * m! * (n-m)  ou simplificando 2^m * (n-m)!    ou
 *                             ( m )                   ------------
 *                                                       (n-2*m)!
 *
 * ainda simplificando, 2^m * (n-m * n-m-1 * ... * n-2*m+1)
 *
 * Aritmetica modular: Dado o valor grande dos operandos, devemos efetuar as
 * operacoes modulo 1300031.
 * Lembrando:
 * - Adicao: (a + b) mod m = ((a mod m)+(b mod m)) mod m
 * - Subtracao: (a - b) mod m = ((a mod m)-(b mod m)) mod m
 * - Multiplicacao: (a * b) mod m = ((a mod m)*(b mod m)) mod m
 * - Exponenciacao: (a^b) mod m = ((a mod m)*(a mod m)) mod m ... b vezes
 * - Divisao: (a/b) mod m = (a mod m) * (b^-1 mod m) mod m -> b^-1 mod m 
 *   inverso de b modulo m. Para encontra-lo, resolver a congruencia
 *   b*x ~ 1 (mod m), ja que bb^-1 ~ 1(mod m).
 *
 */ 


#include <stdio.h>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

/*******************************************************************************
 * Bezout Theorem: Encontra bezout=(a,b) tal que a*x+b*y=gcd(x,y)    
 */
ii find_bezout(int x, int y) {
    if (!y) return ii(1, 0);
    ii u = find_bezout(y, x%y);
    return ii(u.second, u.first - (x/y)*u.second);
}

/*******************************************************************************
 * Resolve a equacao a*x=b (mod m) ou retorna -1 se a solucao
 * nao existir. Pode ser usado para inverter um numero modulo m ou dividir
 * um numero modulo m.
 */
int mod(int x, int m) { return x%m + (x<0 ? m : 0); }
int solve_mod(int a, int b, int m) {
    if (m < 0) return solve_mod(a, b, -m);
    if (a<0 || a>=m || b<0 || b>=m) return solve_mod(mod(a,m), mod(b,m), m);
    ii t = find_bezout(a,m);
    int d = t.first*a + t.second*m;
    return (b%d) ? -1 : mod(t.first*(b/d), m);
}
int inv_mod(int x, int m) { return solve_mod(x,1,m); }
int div_mod(ll a, ll b, int m) { return (a%m * solve_mod(b,1,m)) % m; }

/*******************************************************************************
 * Combinacao n c a c retornando o resultado modulo m.
 */
int ncc_mod(int n, int c, int m) {
    int k = c > (n-c) ? c : n-c;
    ll e = 1, d = 1;
    for (int j = 1, i = k+1; i <= n; i++, j++) e=(e*i)%m, d=(d*j)%m;
    return div_mod(e, d, m);
}


int main() {

    int t, n, m, i;
    ll num, den;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for (num = i = 1; i <= m; i++) num = (num<<1)%1300031;
        for (i = n-2*m+1; i <= n-m; i++) num = (num*i)%1300031;
        printf("%d\n", (int)num);
  }

  return 0;
}

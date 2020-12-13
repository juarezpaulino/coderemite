/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<ios>
using namespace std;
int main() {
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	printf("%d",min(min(min(2*(a+b),a+b+c),2*(a+c)),2*(b+c)));
}
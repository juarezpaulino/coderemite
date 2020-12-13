/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int> compras;
priority_queue<int> vendas;

int n;

int main()
{
	int i, a, b, lucro;
	char c;

	while (scanf("%d",&n)) {
		if (!n) break;
		lucro = 0;
		for (i=0; i<n; i++) {
			scanf(" %c %d.%d", &c, &a, &b);
			if (c == 'C') compras.push(a*100+b);
			else vendas.push(-(a*100+b));
			if (!vendas.empty() && !compras.empty() && (-compras.top() <= vendas.top())) {
				lucro += vendas.top()+compras.top(); vendas.pop(); compras.pop();
			}
		}
		printf("%d.%02d\n", lucro/100, lucro%100);
		while (!vendas.empty()) vendas.pop();
		while (!compras.empty()) compras.pop();
	}

	return 0;
}

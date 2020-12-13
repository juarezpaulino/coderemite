/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
n = parseInt(readline())
a = 1, b = 2, t = 3
for (k = 1; k <= n; k++)
	write((k < 3) ? 'O' : (k == a+b) ? (t = a+b, a = b, b = t, 'O') : 'o')
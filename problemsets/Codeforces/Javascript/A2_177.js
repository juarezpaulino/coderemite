/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
n = parseInt(readline())
s = 0
for (i = 0; i < n; i++) {
	a = readline().split(' ').map(Number)
	for (j = 0; j < n; j++) {
		if (i==j||i+j==n-1||i==Math.floor(n/2)||j==Math.floor(n/2)) s += a[j]
	}
}
print(s)
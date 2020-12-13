/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
n = readline().split(' ').map(Number)[0]
r1 = r2 = c = -1
for (i = 0; i < n; i++) {
	a = readline()
	if (a.includes('B')) {
		if (r1==-1) r1 = i
		r2 = i
		c = (a.lastIndexOf('B')+a.indexOf('B'))/2
	}
}
print((r1+r2)/2+1, c+1)

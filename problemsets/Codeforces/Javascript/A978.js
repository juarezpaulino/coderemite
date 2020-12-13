/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
readline()
d = {}
r = []
readline().split(' ').reverse().map(x => {
	if (!d[x]) { d[x] = 1; r.push(x) }
})
print(r.length)
print(r.reverse().join(" "))
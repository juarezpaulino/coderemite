/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
n = parseInt(readline()), r = 0
v = ""
while (n--) {
	u = readline()
	if (u != v)
		v = u, r++
}
print(r)

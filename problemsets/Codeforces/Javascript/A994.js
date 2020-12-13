/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
readline()
a = readline().split(' ').map(Number)
b = new Set(readline().split(' ').map(Number))
print(a.filter(x=>b.has(x)).join(" "))
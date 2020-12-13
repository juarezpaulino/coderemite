/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
n = readline()
a = readline().split(' ')
v = Math.max.apply(Math, a)
print(a.reduce((r,x) => r + v-x, 0))
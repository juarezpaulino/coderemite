/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
a = readline().split(' ').map(Number)
print(readline().split('').reduce((r,x) => r + a[x-1], 0))
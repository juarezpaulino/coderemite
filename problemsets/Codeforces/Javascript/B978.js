/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
readline()
print(readline().replace(/(?!x)./g,' ').split(' ').filter(x => x.length > 2).reduce((s, a) => s + a.length - 2, 0))

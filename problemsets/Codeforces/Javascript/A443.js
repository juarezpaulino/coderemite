/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
print(Object.keys(eval('('+readline().replace(/,/g,": 1,").replace(/(\w)}/g,"$1: 1}")+')')).length)
/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
readline();
v = {}
readline().split(' ').map(Number).forEach(x => v[x]?v[x]++:v[x]=1)
print(Math.max.apply(null, Object.keys(v).map(x=>v[x])))
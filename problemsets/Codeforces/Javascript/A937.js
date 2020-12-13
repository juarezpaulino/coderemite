/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
readline()
a = readline().split(' ')
							.map(Number)
							.filter(x=>x!=0)
							.reduce((m,x)=>{m[x]=true;return m},{})
print(Object.keys(a).length)
/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
n=+readline()
x=0
print(readline().split(' ').map(Number).reduce((s,a)=>s+((x=a>0?Math.max(a,x+a):x-1)<0?1:0),0))

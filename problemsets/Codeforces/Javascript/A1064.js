/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
a = readline().split(' ').map(Number).sort((a,b)=>a-b);
print(a[2] < a[0]+a[1] ? 0 : a[2]-a[0]-a[1]+1)
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[x.strip() for x in [*open(0)]]
n,k=max(map(len,a)),0
h='*'*(n+2)
print(h)
for x in a:
  u=[n-len(x)>>1]*2
  if len(x)%2 != n%2:
    k^=1
    u[k]+=1
  print('*'+u[0]*' '+x+' '*u[1]+'*')
print(h)
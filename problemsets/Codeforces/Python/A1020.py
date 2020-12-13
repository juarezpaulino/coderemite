"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
f=abs
n,_,a,b,k=I()
while k:
  p,q,u,v=I()
  P=[a,b]
  if a<=q<=b:P+=[q]
  if a<=v<=b:P+=[v]
  print([min(f(q-x)+f(v-x)for x in P)+f(p-u),f(q-v)][p==u])
  k-=1
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,k=I()
b=*I(),
exec('r=['+k*'[],'+']')
for i,x in enumerate(b):r[i]+=[x]
i=0
for j in range(1,n*k+1):
  if j in b: continue
  while len(r[i])==n:i+=1
  r[i]+=[j]
for i in range(k):print(*r[i])
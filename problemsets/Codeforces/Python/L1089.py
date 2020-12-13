"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,k=I()
a=*I(),
b=*I(),
c=[0]*(k+1)
for x in a:c[x]+=1
l=k-len({*a})
a=sorted(zip(b,a))
r=0
for i in range(n):
  if l<1:break
  if c[a[i][1]]>1:
    r+=a[i][0]
    c[a[i][1]]-=1
    l-=1
print(r)
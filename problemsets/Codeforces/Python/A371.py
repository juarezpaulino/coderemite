"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,k=I()
z=n//k
a=*I(),
r=0
for i in range(k):
  b=a[i::k]
  x=b.count(1)
  r+=min(x,z-x)
print(r)
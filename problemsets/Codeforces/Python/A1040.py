"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,*a=*I(),
c=*I(),
r=[0,min(a)][n%2 and c[n//2]==2]
for i in range(n//2):
  if c[i]^c[-1-i]==1:
    r=-1
    break
  if c[i]==2==c[-1-i]:r+=2*min(a)
  elif c[i]==2:r+=a[c[-1-i]]
  elif c[-1-i]==2:r+=a[c[i]]
print(r)
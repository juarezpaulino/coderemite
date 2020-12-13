"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=*map(int,input().split()),
r=1
for i in range(n):
  x=y=a[i]
  k=j=i
  while j-1>=0 and a[j-1]<=x:j-=1;x=a[j]
  while k<n and a[k]<=y:y=a[k];k+=1
  r=max(r,k-j)
print(r)

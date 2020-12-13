"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=*map(int,input().split()),
x=y=0
for x in range(n-1,0,-1):
  if a[x]!=a[0]:break
for y in range(n-1):
  if a[y]!=a[-1]:break
y=n-1-y
print(max(x,y))
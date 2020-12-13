"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,d=I()
a=*I(),
x=a[0]
r=0
for y in a[1:]:
  z=0--(x+1-y)//d
  if z>=0:
    r+=z
    y+=z*d
  x=y
print(r)

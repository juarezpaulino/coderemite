"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r,d=map(int,input().split())
n=int(input())
s=0
for _ in[0]*n:
  x,y,z=map(int,input().split())
  if z>r:continue
  w=x*x+y*y
  s+=(r-z)**2>=w>=(r-d+z)**2
print(s)
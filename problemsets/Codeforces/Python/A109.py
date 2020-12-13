"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
r=(-1,0)
a=0
while a*4<=n:
  c=n-4*a
  if c%7<1:
    b=c//7
    if r[0]<0 or sum(r)>a+b or sum(r)==a+b and b<r[1]:
      r=(a,b)
  a+=1
print([r[0]*'4'+r[1]*'7',-1][r[0]<0])
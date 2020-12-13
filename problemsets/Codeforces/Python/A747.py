"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
x=1
while x*x<=n:
  if n%x<1:r=x
  x+=1
print(r,n//r)
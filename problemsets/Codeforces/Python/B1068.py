"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
b=int(input())
r,x=0,1
while x*x<b:
  if b%x<1:
    r+=2
  x+=1
if x*x==b:r+=1
print(r)
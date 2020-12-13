"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
x=y=1
r=0
while (x<=n):
  r+=1
  y+=1
  x=int(bin(y)[2:])
print(r)
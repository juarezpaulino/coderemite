"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
x=int(n**0.5)
while x:
  if n%x<1:
    break
  x-=1
print(2*(x+n//x))
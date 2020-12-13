"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
x=int(input())
while n%6:
  n+=1
  if n%2:
    if x<2:x^=1
  else:
    if x>0:x=(x-1^1)+1
print(x)
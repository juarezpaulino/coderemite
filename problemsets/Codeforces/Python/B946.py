"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a,b=map(int,input().split())
while 1:
  if a==0 or b==0:break
  if a>=2*b:
    a=a%(2*b)
    continue
  if b>=2*a:
    b=b%(2*a)
    continue
  break
print(a,b)
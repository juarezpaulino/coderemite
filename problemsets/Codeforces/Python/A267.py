"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in [*open(0)][1:]:
  a,b=map(int,s.split())
  r=0
  while a and b:
    if b>a:r+=0--(b-a)//a;b%=a
    else:r+=0--(a-b)//b;a%=b
  print(r+1)
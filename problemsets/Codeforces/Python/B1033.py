"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in [*open(0)][1:]:
  a,b=map(int,s.split())
  x=2
  y=a+b
  while x*x<=y:
    if y%x==0:break
    x+=1
  print('YNEOS'[x*x<=y or a-b>1::2])

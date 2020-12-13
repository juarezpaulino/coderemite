"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
f=lambda x:(3*x*x+x)//2
for _ in[0]*int(input()):
  n=int(input())
  r=0
  while n>1:
    r+=1
    x=int(((1+24*n)**0.5-1)/6)
    n=n-f(x)
  print(r)
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
f=lambda x:x*(x+1)//2
r=[]
for _ in[0]*int(input()):
  n=int(input())-1
  x=int(((8*n+1)**.5-1)//2)
  r+=[[1,0][n-f(x)>0]]
print(*r)
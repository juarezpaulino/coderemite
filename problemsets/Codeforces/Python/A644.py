"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,a,b=map(int,input().split())
if a*b<n:print(-1)
else:
  x=1
  for i in range(a):
    a=*map(lambda x:[x,0][x>n],range(x,x+b)),
    if b%2<1 and i%2:a=a[::-1]
    print(*a)
    x+=b
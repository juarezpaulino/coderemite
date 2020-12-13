"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in [0]*int(input()):
  a,b,c,d,k=map(int,input().split())
  x,y=(a+c-1)//c,(b+d-1)//d
  print(-1) if x+y>k else print(x,y)
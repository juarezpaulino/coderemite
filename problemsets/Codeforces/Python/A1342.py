"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:[*map(int,input().split())]
for _ in[0]*I()[0]:
  x,y=sorted(I())
  a,b=I()
  print(min(a*(x+y),b*x+a*(y-x)))
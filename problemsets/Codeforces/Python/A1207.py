"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in '0'*int(input()):
  b,p,f=map(int,input().split())
  h,c=map(int,input().split())
  if h<c: h,c,p,f=c,h,f,p
  b//=2; t=min(p,b); b-=t
  print(h*t+c*min(b,f))
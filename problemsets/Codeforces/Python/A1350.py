"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n,k=map(int,input().split())
  x=2
  while x*x<=n:
    if n%x==0:break
    x+=1
  if n%x:x=n
  print((k-1)*2+n+x)
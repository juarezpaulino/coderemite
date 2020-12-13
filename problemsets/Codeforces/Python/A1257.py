"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in [0]*int(input()):
  n,x,*a=map(int,input().split())
  a=sorted(a)
  b=a[0]-a[1]
  print(min(x,n-1+b)-b)
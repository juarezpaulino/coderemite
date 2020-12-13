"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,m=map(int,input().split())
r=0
while n:
  a,b=map(int,input().split())
  if a>r:break
  r=max(r,b)
  n-=1
print('YNEOS'[r<m::2])
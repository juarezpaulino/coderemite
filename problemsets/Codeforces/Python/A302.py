"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,m=I()
x=sum(x>0 for x in I())
x=min(x,n-x)
o=[]
while m:
  l,r=I()
  o+=[[0,1][(r-l)%2 and (r-l+1)//2<=x]]
  m-=1
print(*o)
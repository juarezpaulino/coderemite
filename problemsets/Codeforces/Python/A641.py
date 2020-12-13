"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=input()
d=*map(int,input().split()),
x=0
v=[1,-1]
for i in range(n+1):
  x+=v[a[x]=='<']*d[x]
  if x<0 or x>=n:break
print('IN'*(i>=n)+'FINITE')
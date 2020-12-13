"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
m,n=map(int,input().split())
r=[]
x=2*m
for i in range(1,x+1):
  if i+x<=n:r+=[i+x]
  if i<=n:r+=[i]
print(*r) 
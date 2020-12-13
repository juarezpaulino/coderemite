"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,k=map(int,input().split())
a=[]
for _ in[0]*n:
  x,y=map(int,input().split())
  a+=[51*(100-x)+y]
a=sorted(a)
r=i=l=0
while i<n and (a[i]==l or i<k):
  if a[i]!=l:r=0
  r+=1
  l=a[i]
  i+=1
print(r)

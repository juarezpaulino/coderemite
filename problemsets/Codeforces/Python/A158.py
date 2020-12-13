"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,k=I()
a=*I(),
r=[0,1][a[0]>0]
for x,y in zip(a,a[1:]):
  if y<1 or y<x and k<2:break
  r+=1;k-=1
print(r)
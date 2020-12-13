"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,k=I()
a=[[*map(int,input().split())]for _ in[0]*n]
r=0
for u,v in zip(a,a[1:]):
  r+=((u[0]-v[0])**2+(u[1]-v[1])**2)**0.5
print(r*k/50)
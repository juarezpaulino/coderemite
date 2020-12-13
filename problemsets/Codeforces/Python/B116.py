"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
m,n=map(int,input().split())
a=[input()for _ in[0]*m]
y=[-1,0,1,0]
x=[0,-1,0,1]
r=0
for i in range(m):
  for j in range(n):
    if a[i][j]=='W':
      for k in range(4):
        u=i+y[k]
        v=j+x[k]
        if u>=0 and v>=0 and u<m and v<n and a[u][v]=='P':
          r+=1
          break
print(r)
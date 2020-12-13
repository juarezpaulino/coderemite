"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,m=map(int,input().split())
s,t=input(),input()
r=[0]*(m+1)
for i in range(m-n+1):
  a=[j+1 for j,x in enumerate(zip(s,t[i:i+n])) if x[0]!=x[1]]
  if len(a)<len(r):r=a
print(len(r))
print(*r)

"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=[[*map(int,input().split())]for _ in[0]*n]
b=[*zip(*a)]
r=0
for i in range(n):
  for j in range(n):
    if sum(b[j])>sum(a[i]):
      r+=1
print(r)
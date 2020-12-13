"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n=int(input())
  a=*map(int,input().split()),
  r=[1]*n
  for i in range(n):
    j=2*i+1
    while j<n:
      if a[j]>a[i]:r[j]=max(r[j],r[i]+1)
      j+=i+1
  print(max(r))
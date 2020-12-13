"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n,k=map(int,input().split())
  a=sorted(map(int,input().split()))
  b=sorted(map(int,input().split()))[::-1]
  i=0
  while k and a[i]<b[i]:a[i]=b[i];i+=1;k-=1
  print(sum(a))

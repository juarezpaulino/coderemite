"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n=int(input())
  a=*map(int,input().split()),
  r=0
  for x in a:
    i=j=c=0
    while j<n:
      while j<n and (c<x or j-i<2):c+=a[j];j+=1
      if j-i>1 and c==x:
        r+=1
        break
      while c>x:c-=a[i];i+=1
      if j-i>1 and c==x:
        r+=1
        break
  print(r)



"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,m=map(int,input().split())
p=sorted(map(int,input().split()))
a={}
for _ in range(m):
  x=input()
  a[x]=a.get(x,0)+1
a=sorted(a.values())[::-1]
print(sum(x*y for x,y in zip(a,p)),sum(x*y for x,y in zip(a,p[::-1])))
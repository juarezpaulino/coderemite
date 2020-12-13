"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,k=map(int,input().split())
p=[x for x in range(2,n+1)if all(x%i>0 for i in range(2,int(x**0.5)+1))]
s=set()
for x,y in zip(p,p[1:]):
  u=x+y+1
  if u>n:break
  if u in p:s|={u}
print('YNEOS'[len(s)<k::2])
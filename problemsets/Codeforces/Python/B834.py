"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,k=map(int,input().split())
a=input()
d={}
for i in range(n):d[a[i]]=i
s=set()
for i in range(n):
  s|={a[i]}
  if len(s)>k:break
  if i==d[a[i]]:s-={a[i]}
print('YNEOS'[len(s)<=k::2])
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
t=int(input())
while t:
  n=int(input())
  a=sorted(map(int,input().split()))
  x=[0,0]
  for v in a:x[v%2]+=1
  o,e=x
  print('YNEOS'[o%2 and e%2 and all(y-x!=1 for x,y in zip(a,a[1:])) or o%2^e%2::2])
  t-=1
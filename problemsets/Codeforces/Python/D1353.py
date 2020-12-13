"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import heapq
for _ in[0]*int(input()):
  n=int(input())
  q=[]
  heapq.heappush(q,(-n,0,n-1))
  a=[0]*n
  i=1
  while len(q):
    x,l,r=heapq.heappop(q)
    m=l+r>>1
    a[m]=i
    i+=1
    if l!=m:heapq.heappush(q,(l-m,l,m-1))
    if r!=m:heapq.heappush(q,(m-r,m+1,r))
  print(*a)
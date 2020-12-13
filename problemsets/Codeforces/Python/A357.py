"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import itertools
n=int(input())
a=[*itertools.accumulate(map(int,input().split()))]
x,y=map(int,input().split())
for i in range(n):
  if all(x<=u<=y for u in [a[i],a[n-1]-a[i]]):
    break
print([0,i+2][i<n-1])
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,r,a=int(input()),0,[]
for _ in [0]*n:
  a.append([*map(int,input().split())])
r+=sum(a[n//2])+sum([a[x][n//2] for x in range(n)])
r+=sum([a[i][i] for i in range(n)])
r+=sum([a[i][n-1-i] for i in range(n)])
r-=3*a[n//2][n//2]
print(r)

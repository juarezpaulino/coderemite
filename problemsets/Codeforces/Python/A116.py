"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,r,s=int(input()),0,0
for _ in [0]*n:
  r+=eval('-'.join(input().split()))
  s=min(s,r)
print(-s)
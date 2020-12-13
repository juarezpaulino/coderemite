"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import math
n=int(input())
a=sorted(map(int,input().split()))
d=[1,-1]
r=0
for i in range(n):
  r+=d[i%2]*math.pi*a[-1-i]**2
print(r)
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
x=int(input())
h,m=map(int,input().split())
r=0
while h!=7 and h!=17 and m%10!=7:
  if m<x:h=(h+23)%24
  m=(m+60-x)%60
  r+=1
print(r)

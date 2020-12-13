"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
w,h,k=map(int,input().split());r=0
for _ in [0]*k:
  r+=(w+h<<1)-4;w-=4;h-=4
print(r)
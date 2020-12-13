"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:[*map(int,input().split())]
for _ in[0]*I()[0]:
  n,k=I()
  x=I()
  r=max(x[0]-1,n-x[k-1])
  for i in range(1,k):r=max(r,x[i]-x[i-1]>>1)
  print(r+1)
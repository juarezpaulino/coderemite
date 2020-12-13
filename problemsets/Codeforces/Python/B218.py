"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
n,m=I()
a=sorted(I())
b=a[::-1]
x=y=0;c=d=n
for i in range(m):
  l=min(c,(i+1)*(b[i]-b[i+1]) if i<m-1 else m*b[i])
  k=l//(i+1)
  x+=(i+1)*k*(2*b[i]-k+1)//2
  x+=l%(i+1)*(b[i]-k)
  c-=l
  if c<1:break
for i in range(m):
  l=min(d,a[i])
  y+=l*(2*a[i]-l+1)//2
  d-=l
  if d<1:break
print(x,y)

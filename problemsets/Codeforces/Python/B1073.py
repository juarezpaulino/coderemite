"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
I()
a=*I(),
b=I()
s={0}
i=0
r=[]
for x in b:
  if x in s:
    r+=[0]
    continue
  c=i
  while a[i]!=x:s|={a[i]};i+=1
  s|={a[i]}
  i+=1
  r+=[i-c]
print(*r)
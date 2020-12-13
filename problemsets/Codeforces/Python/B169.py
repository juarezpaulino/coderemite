"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[*input()]
b=sorted(input())
n,m=len(a),len(b)-1
for i in range(n):
  if m<0:break
  if b[m]>a[i]:
    a[i]=b[m]
    m-=1
print(''.join(a))

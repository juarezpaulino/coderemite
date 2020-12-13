"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
y=[-1,0,1,0]
x=[0,-1,0,1]
d='ULDR'
i=j=0
n=int(input())
for c in input():
  v=d.index(c)
  i+=y[v]
  j+=x[v]
print(n-abs(i)-abs(j))

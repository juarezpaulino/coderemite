"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
exec('a=['+3*'[*map(int,input().split())],'+']')
for x in range(1,int(1E5+1)):
  a[0][0]=x
  a[1][1]=sum(a[0])-sum(a[1])
  a[2][2]=sum(a[0])-sum(a[2])
  if all(x>0 and x<1E5+1 for i in range(3) for x in a[i]) and \
     all(sum(x)==sum(a[0])for x in [*zip(*a)]) and \
     sum(a[i][i]for i in range(3))==sum(a[0]) and \
     sum(a[i][2-i]for i in range(3))==sum(a[0]):
     break
  else:a[1][1]=a[2][2]=0
print(*a[0])
print(*a[1])
print(*a[2])
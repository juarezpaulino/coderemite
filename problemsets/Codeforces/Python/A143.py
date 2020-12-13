"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import itertools
I=lambda:map(int,input().split())
a,b=I()
c,d=I()
e,f=I()
for m in itertools.combinations(range(1,10),4):
  for w,x,y,z in itertools.permutations(m):
    if [w+x,y+z,w+y,x+z,w+z,x+y]==[a,b,c,d,e,f]:
      print(f'{w} {x}\n{y} {z}')
      exit(0)
print(-1)
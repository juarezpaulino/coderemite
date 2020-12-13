"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
v=[
  [2,3,4,4],
  [3,4,6,6],
  [4,6,8,8],
  [4,6,8,8]
]
for _ in[0]*int(input()):
  a=input()
  y=ord(a[0])-ord('a')
  x=int(a[1])-1
  x=min(x,7-x)
  y=min(y,7-y)
  print(v[y][x])
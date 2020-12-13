"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[1,2,3,4,6,12]
for _ in[0]*int(input()):
  b=input()
  z=[]
  for r,c in zip(a,a[::-1]):
    d=[]
    for k in range(r):
      d+=[b[k*c:(k+1)*c]]
    if any(''.join(x)=='X'*r for x in[*zip(*d)]):
      z+=[f'{r}x{c}']
  print(len(z),*z)
  
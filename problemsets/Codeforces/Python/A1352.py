"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  n=input()
  m=len(n)
  r=[]
  for i in range(m):
    if n[i]!='0':r+=[n[i]+'0'*(m-1-i)]
  print(len(r))
  print(*r)
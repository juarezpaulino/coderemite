"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in[0]*int(input()):
  input()
  a=b=c=l=0
  for x in sorted(map(int,input().split())):
    if x!=l:
      a+=1
      c=0
    c+=1
    b=max(b,c)
    l=x
  print(max(min(a,b-1),min(a-1,b)))

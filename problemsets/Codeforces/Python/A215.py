"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
input()
a=*I(),
input()
b=*I(),
d={}
for x in a:
  for y in b:
    if y%x<1:
      if y//x not in d:d[y//x]=1
      else:d[y//x]+=1
print(d[max(d.keys())])
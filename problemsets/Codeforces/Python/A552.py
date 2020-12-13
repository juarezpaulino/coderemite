"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r=0
for s in[*open(0)][1:]:
  a,b,c,d=map(int,s.split())
  r+=(c-a+1)*(d-b+1)
print(r)
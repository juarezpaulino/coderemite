"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
s={-1}
for x in[*open(0)][1].split()[::-1]:
  if x not in s:r=x
  s|={x}
print(r)
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r=''
for c in input()[::-1]:
  if len(r)<1 or c>=r[0]:
    r=c+r
print(r)

"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
u=set()
r=0
for s in[*open(0)]:
  if s[0]=='+':u|={s[1:-1]}
  elif s[0]=='-':u-={s[1:-1]}
  else:r+=len(u)*len(s.split(':')[1][:-1])
print(r)
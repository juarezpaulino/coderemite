"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
s='heidi$'
i=0
for x in input():
  if x==s[i]:i+=1
print('YNEOS'[i<5::2])
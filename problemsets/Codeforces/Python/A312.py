"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in [*open(0)][1:]:
  a=s[:5]=='miao.'
  b=s[-6:-1]=='lala.'
  print([['Freda\'s','Rainbow\'s'][a],'OMG>.< I don\'t know!'][a==b])
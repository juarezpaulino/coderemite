"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
x=u=l=d=0
for c in input():
  u|=c.isupper()
  l|=c.islower()
  d|=c.isdigit()
  x+=1
print('TCooor rweecatk'[u&l&d&(x>4)::2])
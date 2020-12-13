"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r=0
for x in map(int,[*open(0)][1].split()):
  r=(r+x-1)%2
  print([2,1][r])
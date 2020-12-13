"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
while 1:
  x=n%10
  print(['O-','-O'][x>4]+'|'+x%5*'O'+'-'+(4-x%5)*'O')
  n//=10
  if n<1:break
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
x=int(input())
a=zip([1,3,2,0],"ABCD")
for b,c in a:
  for y in range(x,x+3):
    if b==y%4:
      print(y-x,c)
      exit()
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
x=abs(a.count('U')-a.count('D'))
x+=abs(a.count('R')-a.count('L'))
print([x//2,-1][x%2])
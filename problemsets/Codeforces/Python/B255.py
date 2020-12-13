"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
x=a.count('x')
y=len(a)-x
print(('yx'[x>y])*abs(x-y))
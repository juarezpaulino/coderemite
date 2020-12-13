"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=input()
x=a.count('x')
if 2*x>n:a=a.replace('x','X',x-n//2)
else:a=a.replace('X','x',n//2-x)
print(abs(2*x-n)//2)
print(a)

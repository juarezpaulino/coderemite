"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
from math import factorial
n=int(input())
print(1 if n==1 else factorial(2*n-2)//factorial(n-1)**2)
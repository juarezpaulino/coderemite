"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
f=lambda x:(x+1)*x//2
print(n-f(int(((8*n-7)**.5-1)/2)))
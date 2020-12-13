"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input());m=n//2
print(m)
print(*([2]*(m-1)),3 if n%2 else 2)
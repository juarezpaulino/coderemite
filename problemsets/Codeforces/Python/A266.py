"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
input()
a=input()
print(sum(x==y for x,y in zip(a,a[1:])))
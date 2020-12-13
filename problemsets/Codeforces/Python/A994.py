"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
i=lambda:input().split()
n,m=map(int,i())
a,b=i(),i()
print(*[x for x in a if x in b])
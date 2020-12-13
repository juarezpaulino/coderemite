"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
c='RBYG'
a=input()
print(*[a[p::4].count('!')for p in[a.index(x)%4 for x in c]])

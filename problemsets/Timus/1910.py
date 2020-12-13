"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[*map(int,[*open(0)][1].split())]
print(*max((sum(x),i+2) for i,x in enumerate(zip(a,a[1:],a[2:]))))
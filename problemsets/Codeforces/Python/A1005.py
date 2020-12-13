"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
input()
a=[*map(int,input().split())]
m=[x for x,y in zip(a,a[1:]+[1]) if y==1]
print(len(m))
print(*m)
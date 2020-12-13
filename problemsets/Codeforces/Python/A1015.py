"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
i=lambda:map(int,input().split())
d=lambda x,y:{*range(x,y+1)}
n,m=i()
a=d(1,m)
for _ in '0'*n:a-=d(*i())
print(len(a))
print(*a)
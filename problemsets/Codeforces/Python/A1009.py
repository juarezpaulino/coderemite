"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
input()
I = lambda:[*map(int,input().split())]
a,b = I(),I()
print(sum(1 for x in a if len(b)>0 and b[0]>=x and b.pop(0)))

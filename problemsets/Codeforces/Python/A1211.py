"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=*map(int,[*open(0)][1].split()),
b=sorted({*a})
print(*[[a.index(x)+1 for x in b[:3]],[-1]*3][len(b)<3])
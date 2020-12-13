"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[0,*map(int,input().split())]
print(sum(a[int(x)] for x in input()))
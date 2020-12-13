"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
d=int(input())
n=int(input())
r=0
for x in map(int,input().split()):r+=d-x
print(r-d+x)

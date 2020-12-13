"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
from functools import reduce
input()
a=0
for _ in[0,0]:a+=reduce(lambda x,y:x|y,map(int,input().split()))
print(a)
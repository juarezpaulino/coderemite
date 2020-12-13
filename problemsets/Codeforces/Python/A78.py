"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
r=0
for i in [0,1,2]:r|=sum(x in 'aeiou' for x in input())!=5+i%2*2
print('YNEOS'[r::2])
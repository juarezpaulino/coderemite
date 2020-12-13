"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
print('YNEOS'[all(x!=y for x,y in zip(I(),I()))::2])
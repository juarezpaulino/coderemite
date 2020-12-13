"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,m=map(int,input().split())
a={input()for _ in[0]*n}
b={input()for _ in[0]*m}
l=len(a&b)
print('YNEOS'[len(a-b)+0--l//2<=len(b-a)+l//2::2])
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
s=input()
n=int(input())
exec('b=['+n*'input(),'+']')
c=[*zip(*b)]
print('NYOE S'[s in b or (s[0]in c[1]and s[1]in c[0])::2])
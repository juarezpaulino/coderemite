"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input().lower()
c='o0'
d='i1l'
print('YNeos'[any(len(a)==len(x) and all(u==v or (u in c and v in c) or (u in d and v in d) for u,v in zip(a,x))for x in [input().lower() for _ in ' '*int(input())])::2])
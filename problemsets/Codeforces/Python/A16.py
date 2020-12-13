"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[*open(0)][1:]
r=any(len({*b})>2 for b in a)
print('YNEOS'[r|any(x[0]==y[0] for x,y in zip(a,a[1:]))::2])
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[*open(0)][1].split()
a,b=[a.count('100'),a.count('200')]
print('YNEOS'[(a+2*b)%2 or b%2 and a<2::2])
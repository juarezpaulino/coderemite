"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[*zip(*[*open(0)][1:])]
print(max(x.count('1') for x in a))

"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[*open(0)][1].split()
print(max(a.count(x)for x in{*a}))
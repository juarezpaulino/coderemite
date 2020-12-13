"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=[x.split() for x in[*open(0)][1::2]]
print(len({*a[0]}&{*a[1]}&{*a[2]}))

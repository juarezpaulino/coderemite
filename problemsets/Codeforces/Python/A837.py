"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
print(max(sum(x.isupper()for x in y)for y in [*open(0)][1].split()))
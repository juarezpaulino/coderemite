"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
print(min({*range(1,3002)}-{*map(int,[*open(0)][1].split())}))
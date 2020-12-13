"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
v=["Danil","Olya","Slava","Ann","Nikita"]
a=input()
print('YNEOS'[sum(a.count(x)for x in v)!=1::2])

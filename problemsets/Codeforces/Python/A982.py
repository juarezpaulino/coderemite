"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
input()
a='0'+input()+'0'
print('YNEOS'[a.count('000')>0 or a.count('11')>0::2])
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
print('YNEOS'[a!=a[::-1]or any(x not in 'AHIMOTUVWXY' for x in a)::2])
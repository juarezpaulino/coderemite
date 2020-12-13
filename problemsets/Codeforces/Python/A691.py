"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=input()
print('NYOE S'[(n<2 and a.count('1')) or (n>1 and a.count('0')==1)::2])
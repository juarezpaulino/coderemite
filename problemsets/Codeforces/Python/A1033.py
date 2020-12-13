"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
input()
a,b=I()
c,d=I()
e,f=I()
print('YNEOS'[(c-a)*(e-a)<0 or (d-b)*(f-b)<0::2])
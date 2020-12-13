"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
k=int(input())
a=''.join([input()for _ in[0]*4])
print('YNEOS'[max((a.count(str(x))for x in range(10)),default=0)>2*k::2])
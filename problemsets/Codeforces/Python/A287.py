"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=''.join([input()for _ in[0]*4])
print('YNEOS'[all([a[x],a[x+1],a[x+4],a[x+5]].count('.')==2 for x in[0,1,2,4,5,6,8,9,10])::2])
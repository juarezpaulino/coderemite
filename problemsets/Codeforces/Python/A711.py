"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import sys
input()
a=sys.stdin.read()
p=a.find('OO')
print('NO' if p<0 else 'YES\n'+a[:p]+'++'+a[p+2:])
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input().split(':')
b=input().split(':')
a=int(a[0])*60+int(a[1])
b=int(b[0])*60+int(b[1])
a=(a+1440-b)%1440
print(f'{a//60:02d}:{a%60:02d}')
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
h,m=map(int,input().split(':'))
a=(int(input())+h*60+m)%1440
print(f'{a//60:02}:{a%60:02}')

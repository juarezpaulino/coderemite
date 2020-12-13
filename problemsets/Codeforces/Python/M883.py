"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
a,b=I()
c,d=I()
print((max(1,abs(a-c))+max(1,abs(b-d))<<1)+4)
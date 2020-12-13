"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
a=*map(int,input().split()),
b=*map(int,input().split()),
s={*a}|{*b}
print('KKaoryeonm i'[sum(x^y in s for x in a for y in b)%2::2])
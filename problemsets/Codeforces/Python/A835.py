"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
s,a,b,c,d=map(int,input().split())
e=2*(c-d)+s*(a-b)
print([['Friendship','First'][e<0],'Second'][e>0])
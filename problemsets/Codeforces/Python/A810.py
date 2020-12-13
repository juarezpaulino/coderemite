"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,k=map(int,input().split())
a=map(int,input().split())
print(max(0,(n*(k*10-5)-sum(a)*10)//5))
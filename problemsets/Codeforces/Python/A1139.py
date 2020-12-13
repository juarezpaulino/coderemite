"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n,a=int(input()),input()
print(sum(i+1 for i in range(n) if int(a[i])%2==0))
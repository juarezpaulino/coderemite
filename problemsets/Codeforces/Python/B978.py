"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
_,a=input(),input()
print(sum(1 for i in range(len(a)-2) if a[i:i+3]=='xxx'))
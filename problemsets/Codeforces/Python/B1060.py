"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=input()
k=len(n)-1
r=k*9+int(n[0])-1
n=str(int(n)-int(str(int(n[0])-1)+'9'*k))
for x in n:r+=int(x)
print(r)
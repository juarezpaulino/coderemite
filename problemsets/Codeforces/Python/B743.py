"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n, k = map(int, input().split())
ret = 1
while k%2==0:
  k/=2;
  ret+=1;
print(ret)
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=sorted(map(int,input().split()))
print(max(0,1+a[-1]-sum(a[:2])))
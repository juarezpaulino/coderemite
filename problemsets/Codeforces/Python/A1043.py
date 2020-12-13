"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n = int(input())
a = list(map(int, input().split()))
print(max(max(a),2*sum(a)//n+1))
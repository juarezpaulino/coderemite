"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
print(sum(1 for p,q in [map(int,input().split()) for _ in [0]*int(input())] if q-p>1))
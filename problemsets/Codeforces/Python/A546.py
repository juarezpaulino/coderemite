"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
k,n,w=map(int,input().split())
print(max(0,(1+w)*k*w//2-n))
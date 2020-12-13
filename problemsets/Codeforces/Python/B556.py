"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
d=[1,-1]
print('YNeos'[len({(d[i%2]*(i-x)+n)%n for i,x in enumerate(map(int,input().split()))})>1::2])

"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
t=int(input())
for _ in [1]*t:
	s,a,b,c=list(map(int,input().split()))
	print(s//c+s//c//a*b)
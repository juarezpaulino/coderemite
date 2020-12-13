"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a, b = map(int, input().split())
for y in range(1,20):
	a, b = a*3, b*2
	if a > b:
		print(y)
		break

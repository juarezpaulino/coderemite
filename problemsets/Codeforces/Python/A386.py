"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
n=int(input())
p=sorted(enumerate(map(int,input().split())),key=lambda x:x[1])
print(p[-1][0]+1,p[-2][1])

"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
I=lambda:map(int,input().split())
m=*I(),
w=*I(),
s,u=I()
p=[500,1000,1500,2000,2500]
print(sum(max(3*p[i]//10,(250-m[i])*p[i]//250-50*w[i])for i in range(5))+s*100-u*50)
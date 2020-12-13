"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
F=open('input.txt','r')
W=open('output.txt','w')
I=lambda:map(int,F.readline().split())
n,k=I()
a=sorted(zip(I(),range(n)))[::-1]
W.write(str(a[k-1][0])+'\n'+' '.join(map(str,[y+1 for x,y in a[:k]])))
W.close()

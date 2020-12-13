"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
F=open('input.txt','r')
W=open('output.txt','w')
a=F.readline()
b=int(F.readline())
W.write(str('RL'[a[0]=='f'and b<2 or a[0]=='b'and b>1]))
W.close()

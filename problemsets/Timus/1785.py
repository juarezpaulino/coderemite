"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
v=[5,10,20,50,100,250,500,1000]
r=['few','several','pack','lots','horde','throng','swarm','zounds','legion']
i=0
x=int(input())
while i<8 and x>=v[i]:i+=1
print(r[i])
"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
c=[0]*5
for x in map(int,[*open(0)][1].split()):
  c[x]+=1
c[1]=max(0,c[1]-c[3])
c[1]=max(0,c[1]-c[2]%2*2)
c[1]=0--c[1]//4
c[2]=0--c[2]//2
print(sum(c))
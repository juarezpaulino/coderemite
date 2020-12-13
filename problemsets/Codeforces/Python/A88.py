"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
c=['C','C#','D','D#','E','F','F#','G','G#','A','B','H']
x,y,z=sorted(map(c.index,input().split()))
for _ in' '*3:
  a,b=(y+12-x)%12,(z+12-y)%12
  if [a,b]==[4,3]:
    print('major')
    exit()
  if [a,b]==[3,4]:
    print('minor')
    exit()
  x,y,z=y,z,x
print('strange')
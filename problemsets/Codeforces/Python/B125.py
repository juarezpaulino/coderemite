"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
c=0
for x in input().replace('<',' ').replace('>',' ').split():
  if x[0]=='/':c-=1
  print(c*'  ',end='')
  if x[0]=='/':print('</'+x[1]+'>')
  else:c+=1;print('<'+x[0]+'>')
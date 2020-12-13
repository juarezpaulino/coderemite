"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
a=input()
n=0
b='00'
if '-'in a:n=1;a=a[1:]
if '.'in a:
  a,b=a.split('.')
  if len(b)>2:b=b[:2]
  if len(b)<2:b+='0'
a=a[::-1]
r=''
for i in range(0,len(a),3):r+=','+a[i:i+3]
r='$'+r[1:][::-1]+'.'+b
if n:r='('+r+')'
print(r)

  

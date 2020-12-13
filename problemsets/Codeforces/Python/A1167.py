"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
i=lambda:input()
for _ in [0]*int(i()):
  _,s=i(),i()
  print(["NO","YES"]['8' in s and len(s)-s.find('8')>10])
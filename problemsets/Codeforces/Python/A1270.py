"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
i=lambda:map(int,input().split())
for _ in [0]*int(input()):
  i()
  print(['YES','NO'][max(i())<max(i())])
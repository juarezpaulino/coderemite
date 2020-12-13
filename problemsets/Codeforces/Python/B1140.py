"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for s in [*open(0)][2::2]:
  s=s.strip()
  print(len(s)-max(map(len,(s.lstrip('<'),s.rstrip('>')))))
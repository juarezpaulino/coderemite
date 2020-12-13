"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
for _ in range(int(input())):
  s = input()
  print('FILIPINO' if s.endswith('po') else "KOREAN" if s.endswith("mnida") else 'JAPANESE')
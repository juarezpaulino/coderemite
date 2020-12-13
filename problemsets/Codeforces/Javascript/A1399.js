/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
t = parseInt(readline());
while (t--) {
  readline();
  a = readline().split(' ').map(Number).sort((x, y) => x - y);
  r = a.reduce((r, c) => Math.abs(c - r) > 1 ? -1 : c, a[0]);
  print(r > 0 ? "YES" : "NO");
}
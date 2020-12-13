/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
t = parseInt(readline());
while (t--) {
  r = Math.abs(readline().split(' ').map(Number).reduce((r, c) => r - c));
  print(Math.floor(r / 10) + (r % 10 !== 0));
}
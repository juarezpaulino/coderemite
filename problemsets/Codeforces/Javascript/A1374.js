/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
var t = readline();
while (t--) {
  var a = readline().split(' ').map(Number);
  var x = a[0], y = a[1], n = a[2];
  var m = Math.floor(n / x) * x;
  print(m + y > n ? m - (x - y) : m + y);
}
/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
var t = readline();
while (t--) {
  var n = readline();
  a = readline().split(' ').map(Number);
  b = readline().split(' ').map(Number);
  var mA = Math.min(...a);
  var mB = Math.min(...b);
  var r = 0;
  for (var i = 0; i < n; i++) r += Math.max(a[i] - mA, b[i] - mB);
  print(r);
}
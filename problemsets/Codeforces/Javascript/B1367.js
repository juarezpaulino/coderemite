/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
var t = readline();
while (t--) {
  var n = readline();
  var a = readline().split(' ').map(Number);
  var o = 0, e = 0;
  for (var i = 0; i < n; i++)
    if (i % 2 !== a[i] % 2)
      i % 2 ? o++ : e++;
  print(o !== e ? -1 : o);
}
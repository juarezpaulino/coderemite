/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import "fmt"
import "strings"
func main() {
	var n, m, l, r int
	var a, c1, c2 string
	fmt.Scan(&n,&m,&a)
	for i:=0;i<m;i++ {
		fmt.Scan(&l,&r,&c1,&c2)
		l--
		a = a[:l] + strings.Replace(a[l:r],c1,c2,-1) + a[r:]
	}
	fmt.Print(a)
}
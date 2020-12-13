/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import "fmt"
func main() {
	var n,k int
	fmt.Scan(&n,&k)
	x:=0
	for t:=0; x<n; {
		if t+5*x>235-k {
			break
		}
		x++
		t+=5*x
	}
	fmt.Print(x)
}
/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import "fmt"
func main() {
	var n,x int
	fmt.Scan(&n)
	a,b := 0,0
	for ;n>0;n-- {
		fmt.Scan(&x)
		if x > 0 {
			a += x
		} else {
			b -= x
		}
	}
	fmt.Print(a+b)
}
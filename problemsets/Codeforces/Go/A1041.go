/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import "fmt"
import "math"
func main() {
	var n, x int
	fmt.Scan(&n)
	a := math.MaxInt32
	b:= -1
	for i := 0; i < n; i++ {
		fmt.Scan(&x)
		if x < a {
			a = x
		}
		if x > b {
			b = x
		}
	}
	fmt.Print(b+1-a-n)
}
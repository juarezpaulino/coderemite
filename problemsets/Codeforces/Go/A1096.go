/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import "fmt"
func main() {
	var t, a, b int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		fmt.Scan(&a,&b)
		fmt.Println(a,a*2)
	}
}
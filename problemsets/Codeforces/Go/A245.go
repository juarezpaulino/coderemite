/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import "fmt"
func main() {
	var n, t, a, b int
	fmt.Scan(&n)
	v := []int{0,0,0}
	for i:=0; i<n; i++ {
		fmt.Scan(&t, &a, &b)
		v[t] += a-b
	}
	for i:=1; i < 3; i++ {
		if v[i]>=0 {
			fmt.Println("LIVE")
		} else {
			fmt.Println("DEAD")
		}
	}
}
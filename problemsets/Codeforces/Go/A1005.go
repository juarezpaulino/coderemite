/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import "fmt"
func main() {
	var n, x int
	l := 0
	r := []int{}
	fmt.Scan(&n)
	for i:=0; i < n; i++ {
		fmt.Scan(&x)
		if x <= l {
			r = append(r, l)
		}
		l = x
	}
	r = append(r, l)
	fmt.Println(len(r))
	for _,x := range r {
		fmt.Printf("%d ", x)
	}
}
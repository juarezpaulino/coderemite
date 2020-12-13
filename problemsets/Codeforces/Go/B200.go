/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main

import "fmt"

func main() {
	var n int
	var x, r float64
	fmt.Scan(&n)
	for i:=0; i<n; i++ {
		fmt.Scan(&x)
		r += x
	}
	fmt.Println(r/float64(n))
}
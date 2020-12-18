/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main

import "fmt"

func main() {
	var T, n, x int
	fmt.Scan(&T)
	for t := 0; t < T; t++ {
		fmt.Scan(&n, &x)
		r := 1
		for m := n - 2; m > 0; m -= x {
			r++
		}
		fmt.Println(r)
	}
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main

import "fmt"

func main() {
	var T, a, b, n, r int
	fmt.Scan(&T)
	for t := 0; t < T; t++ {
		fmt.Scan(&a, &b, &n)
		if b < a {
			a, b = b, a
		}
		for r = 0; b <= n; r++ {
			a, b = b, a+b
		}
		fmt.Println(r)
	}
}

/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main

import "fmt"

func main() {
	var t, n int
	fmt.Scan(&t)
	for c := 0; c < t; c++ {
		fmt.Scan(&n)
		for i := 2; i <= n; i++ {
			fmt.Printf("%d ", i)
		}
		fmt.Println("1")
	}
}

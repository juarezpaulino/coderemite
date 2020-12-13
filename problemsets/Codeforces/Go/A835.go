/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main

import "fmt"

func main() {
	var n, a, b, c, d int
	fmt.Scan(&n,&a,&b,&c,&d)
	x := n*a+2*c; y := n*b+2*d
	if x < y {
		fmt.Print("First")
	} else if x > y {
		fmt.Print("Second")
	} else {
		fmt.Print("Friendship")
	}
}
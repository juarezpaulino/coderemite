/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main

import "fmt"

func main() {
	var l1, l2, r1, r2, q int
	fmt.Scan(&q)
	for i:=0; i < q; i++ {
		fmt.Scan(&l1, &l2, &r1, &r2)
		if r2 <= l1 {
			fmt.Printf("%d %d\n", l2, r1)
		} else {
			fmt.Printf("%d %d\n", l1, r2)
		}
	}
}
/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main

import "fmt"

func main() {
	var T, n, m int
	fmt.Scan(&T)
	for t := 0; t < T; t++ {
		fmt.Scan(&n, &m)
		a := make([]int, n)
		r := -1
		for i, _ := range a {
			fmt.Scan(&a[i])
		}
		for i, el := 0, 0; i < m; i++ {
			fmt.Scan(&el)
			for _, el2 := range a {
				if el == el2 {
					r = el
				}
			}
		}
		if r == -1 {
			fmt.Println("NO")
		} else {
			fmt.Println("YES")
			fmt.Printf("1 %d\n", r)
		}
	}
}

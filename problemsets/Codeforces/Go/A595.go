/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main

import "fmt"

func main() {
	var n, m int
	r := 0
	fmt.Scan(&n, &m)
	for i:=0;i<n*m;i++ {
		var a, b int
		fmt.Scan(&a,&b)
		if a+b>0 {
			r++
		}
	}
	fmt.Print(r)
}
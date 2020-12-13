/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	var m, a, b float64
	var ret float64 = math.MaxFloat64
	fmt.Scan(&n, &m)
	for i:=0; i < n; i++ {
		fmt.Scan(&a, &b)
		if x := a/b; x < ret {
			ret = x;
		}
	}
	fmt.Println(ret*m)
}
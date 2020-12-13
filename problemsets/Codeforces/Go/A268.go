/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import "fmt"
func main() {
	var n,x,y int
	var h,a [110]int
	fmt.Scan(&n)
	for ;n>0;n-- {
		fmt.Scan(&x,&y)
		h[x]++; a[y]++
	}
	r:=0
	for i:=1;i<101;i++ {
		r += a[i]*h[i]
	}
	fmt.Print(r)
}
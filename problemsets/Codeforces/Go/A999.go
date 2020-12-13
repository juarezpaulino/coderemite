/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import "fmt"
func main() {
	var n, k int
	fmt.Scan(&n,&k)
	a := make([]int,n)
	for i:=0;i<n;i++ {
		fmt.Scan(&a[i])
	}
	r := 0
	for i:=0;i<n&&a[i]<=k;i++ {
			r++
	}
	for i:=n-1;i>=0&&r<n&&a[i]<=k;i-- {
		r++
	}
	fmt.Print(r)
}
/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import "fmt"
type data struct {
	v	int
	i	int
}
func main() {
	var n,x,y int
	fmt.Scan(&n)
	a:=make([]data,n)
	for i:=0;i<n;i++ {
		fmt.Scan(&x)
		a[i]=data{x,i}
	}
	for k:=0;k<n;k+=2 {
		u:=0
		for i:=1;i<n-k;i++ {
			if a[i].v < a[u].v {
				u = i
			}
		}
		x = a[u].i
		a = append(a[:u],a[u+1:]...)
		v:=0
		for i:=1;i<n-k-1;i++ {
			if a[i].v > a[v].v {
				v = i
			}
		}
		y = a[v].i
		a = append(a[:v],a[v+1:]...)
		fmt.Println(x+1,y+1)
	}	
}
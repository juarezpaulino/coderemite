/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main
import (
	"fmt"
	"bufio"
	"os"
	"strconv"
)
func main() {
	var n, c int
	r,y := 0,0
	fmt.Scan(&n,&c)
	scan := bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)
	for scan.Scan() {
		x,_ := strconv.Atoi(scan.Text())
		if x-y>c {
			r = 0
		}
		y = x
		r++
	}
	fmt.Print(r)
}
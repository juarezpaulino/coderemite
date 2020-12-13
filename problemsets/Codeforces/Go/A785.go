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
)

func main() {
	var n, ret  int
	var m [256]int
	m['I'] = 20
	m['D'] = 12
	m['O'] = 8
	m['C'] = 6
	m['T'] = 4
	fmt.Scan(&n)
	scan := bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)
	for scan.Scan() {
		ret += m[scan.Text()[0]]
	}
	fmt.Println(ret)
}
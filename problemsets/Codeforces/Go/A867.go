/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
package main

import (
	"fmt"
	"regexp"
	"bufio"
	"os"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	scan.Scan(); scan.Scan()
	s := scan.Text()
	fs := regexp.MustCompile("FS")
	sf := regexp.MustCompile("SF")
	if len(sf.FindAllStringIndex(s, -1)) > len(fs.FindAllStringIndex(s, -1)) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
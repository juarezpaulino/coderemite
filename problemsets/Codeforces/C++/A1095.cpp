/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
int main() {
	std::string s;
	std::cin >> s >> s;
	for (int i = 0, l = 0; i < s.size(); i+=++l) putchar(s[i]);
}
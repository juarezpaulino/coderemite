/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {

    string a, b, c;
    cin >> a >> b >> c;
    if (a == "vertebrado" && b == "ave" && c == "carnivoro") puts("aguia");
    else if (a == "vertebrado" && b == "ave" && c == "onivoro") puts("pomba");
    else if (a == "vertebrado" && b == "mamifero" && c == "onivoro") puts("homem");
    else if (a == "vertebrado" && b == "mamifero" && c == "herbivoro") puts("vaca");
    else if (a == "invertebrado" && b == "inseto" && c == "hematofago") puts("pulga");
    else if (a == "invertebrado" && b == "inseto" && c == "herbivoro") puts("lagarta");
    else if (a == "invertebrado" && b == "anelideo" && c == "hematofago") puts("sanguessuga");
    else if (a == "invertebrado" && b == "anelideo" && c == "onivoro") puts("minhoca");

    return 0;
}

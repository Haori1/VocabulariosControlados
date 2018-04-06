#include <iostream>
#include <string>
#include "dominiosClasses.hpp"

int main(void) {
    Nome x;
    string a;
    cin >> a;
    x.setNome(a);
    string b = x.getNome();
    cout << b << endl;
    return 0;
}

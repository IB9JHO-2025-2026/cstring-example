#include <iostream>
#include "cstring.h"

int main() {
    Cstring mystring("hello");
    std::cout << mystring.get() << std::endl; // prints hello

    // copy constructor
    Cstring mystring2 = Cstring(mystring);
    // copy constructor
    Cstring mystring3 = mystring;
    // copy constructor
    Cstring mystring4(mystring);
    // copy-assignment operator (not initialisation)
    mystring4 = Cstring("goodbye"); 
    // The RHS object is created and destroyed on above line
}
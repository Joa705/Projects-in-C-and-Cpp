#include <iostream>
#include "parser.h"

using namespace std;


int main() {
    char *exp;
    exp = "2+5";


    if( NotEmpty(exp)){
        cout << "not empty" << endl;
    }
    else cout << "empty";

    char nextchar = Nextchar(exp);
    cout << nextchar << endl;






    return 0;
}

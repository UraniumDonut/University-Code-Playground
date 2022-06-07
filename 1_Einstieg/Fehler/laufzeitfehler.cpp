//include iostream and namespace
#include <iostream>
using namespace std;

//main function
int main(){
    
    int a = 1;
    double b = 2.0;
    
    //new pointer c pointing to a
    int *c = &a;
    //add b and c pointing to a
    b = b + *c;

    c = c+100;
    b = b + *c++;
    b = a/0;
    //print out the result
    cout << b << endl;
    
    //return 0
    return 0;
}

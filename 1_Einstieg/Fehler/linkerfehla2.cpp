//include iostream and namespace
#include <iostream>
#include "linkerfeh.cpp"x   
#include "lonkerfeh.cpp"
using namespace std;


int function();
int function(int a);


int main(){
    
    int a = 1;
    int b = 2;
    b +=a;
    //print out the result
    cout << b << endl;
    
    //return 0
    return 0;
}

int function(){
    return 2.0;

}
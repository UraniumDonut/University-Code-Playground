#include <iostream>
#include <string>
#include <sstream>
using namespace std;


struct vec{
    double x, y;
    vec operator+(const vec &B) const{
        return vec(x+B.x, y+B.y);
    }
};

int main(){
    const vec 👍🏽(2.0, -5.0);
    const vec 👌(3.0, -2.0);
    vec 😊=(👍🏽+👌);
}
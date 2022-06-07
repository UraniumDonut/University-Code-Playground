#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class vector2d{
    //variables private
    private:
        double x;
        double y;

    public:
        /*vector2d(double x, double y){
            this->x = x;
            this->y = y;
        }*/
        vector2d(int x, int y):x(x), y(y){cout << "int" << endl;}
        vector2d(const vector2d& v):x(v.x), y(v.y){cout << "copy" << endl;}
        vector2d & operator = (const vector2d & v){x=(v.x), y=(v.y);cout << "assign" << endl;return * this;}
        vector2d & operator += (const vector2d & v){x+=v.x; y+=v.y;cout << "add" << endl;return * this;}
        vector2d operator+(const vector2d & v) const{
            return vector2d(x+v.x, y+v.y);
        }
        vector2d operator-(const vector2d & v) const{
            return vector2d(x-v.x, y-v.y);
        }
        vector2d operator*(const double & d) const{
            return vector2d(x*d, y*d);
        }
        double operator*(const vector2d & v) const{
            return (x*v.x+ y*v.y);
        }
        ~vector2d(){cout << "Ich bin raus" << endl;}
        vector2d add(const vector2d &B) const{
            return vector2d(x+B.x, y+B.y);
        }
        void set(double x, double y){
            this->x = x;
            this->y = y;
        }
        void get(double &x, double &y) const{
            x = this->x;
            y = this->y;
        }
        string text() const{
            stringstream s;
            s << "(" << x << "," << y << ")";
            return s.str();
        }
};


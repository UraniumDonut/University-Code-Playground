#include "vector2d.h"



        vector2d::vector2d(int x, int y):x(x), y(y){}
        vector2d::vector2d(double x, double y):x(x), y(y){}
        vector2d::vector2d(const vector2d& v):x(v.x), y(v.y){}
        vector2d & vector2d::operator = (const vector2d & v){x=(v.x), y=(v.y);return * this;}
        vector2d & vector2d::operator += (const vector2d & v){x+=v.x; y+=v.y;return * this;}
        vector2d vector2d::operator+(const vector2d & v) const{
             return vector2d(x+v.x, y+v.y);
         }
        vector2d vector2d::operator-(const vector2d & v) const{
             return vector2d(x-v.x, y-v.y);
         }
        vector2d vector2d::operator*(const double & d) const{
             return vector2d(x*d, y*d);
         }
        double vector2d::operator*(const vector2d & v) const{
             return (x*v.x+ y*v.y);
        }
        vector2d vector2d::add(const vector2d &B) const{
            return vector2d(x+B.x, y+B.y);
        }
        void vector2d::set(double x, double y){
            this->x = x;
            this->y = y;
        }
        void vector2d::get(double &x, double &y) const{
            x = this->x;
            y = this->y;
        }
        string vector2d::text() const{
            stringstream s;
            s << "(" << x << "," << y << ")";
            return s.str();
        }

#include <iostream>
#include <string>
#include <sstream>
#include<windows.h>
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
        vector2d(int x, int y):x(x), y(y){}
        vector2d(double x, double y):x(x), y(y){}
        vector2d(const vector2d& v):x(v.x), y(v.y){}
        vector2d & operator = (const vector2d & v){x=(v.x), y=(v.y);return * this;}
        vector2d & operator += (const vector2d & v){x+=v.x; y+=v.y;return * this;}
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



class body{
    private:
        vector2d position;
        vector2d velocity;
        double mass;
    public:
        body(const vector2d& position, const vector2d& velocity, double mass):position(position), velocity(velocity), mass(mass){}

        void animate(double& dt, vector2d& gravity){
            velocity += gravity*dt;
            position += velocity*dt;
        }
        vector2d get_Position() const{
            return position;
        }
        vector2d get_Velocity() const{
            return velocity;
        }

    
};


void draw(body &b){
    double y, x;
    int y_int, x_int;
    b.get_Position().get(x,y);
    y_int = (int)y;
    x_int = (int)x;
    for (int i = 20; i > 0; i--){
        if(i == y_int){
            for (int j = 0; j < 100; j++){
                if(i == y_int && j == x_int){
                    cout << "*";
                }else{
                    cout << ".";
                }
            }
        }
        else{
            cout << "....................................................................................................";
        }
        cout << endl;
    }
}

int main(){
    double dt = 0.05;
    vector2d gravity(0.0, -9.81);
    body b(vector2d(15.0,10.0), vector2d(10.0,1.0), 1.0);
    vector2d bvec(0.0,0.0), bvel(0.0,0.0);
    while(true){
        draw(b);
        b.animate(dt, gravity);
        Sleep(400);
        
    }
    return 0;
}



#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

class vector2d{

    public:
        double x;
        double y;
        vector2d(int x, int y);
        vector2d(double x=0.0, double y=0.0);
        vector2d(const vector2d& v);
        vector2d & operator = (const vector2d & v);
        vector2d & operator += (const vector2d & v);
        vector2d operator+(const vector2d & v) const;
        vector2d operator-(const vector2d & v) const;
        vector2d operator*(const double & d) const;
        double operator*(const vector2d & v) const;
        vector2d add(const vector2d &B) const;
        void set(double x, double y);
        void get(double &x, double &y) const;
        string text() const;
};


#endif
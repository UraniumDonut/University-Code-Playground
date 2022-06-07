#ifndef VERKEHRSMITTEL_H
#define VERKEHRSMITTEL_H

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "vector2d.h"

using namespace std;

class Verkehrsmittel{
    private:
        string bezeichnung;
        vector2d ort;
    public:
        Verkehrsmittel(string bezeichnung, vector2d ort);
        Verkehrsmittel(const string& bezeichnung);
        Verkehrsmittel(const Verkehrsmittel& v);
        string name() const;
        vector2d position() const;
        ~Verkehrsmittel();
        void bewegezu(vector2d position);
        string text() const;
};

#endif
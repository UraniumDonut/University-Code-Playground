#ifndef RADFAHRZEUG_H
#define RADFAHRZEUG_H

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "vector2d.h"
#include "Verkehrsmittel.h"


class Radfahrzeug : public Verkehrsmittel{
    private:
        int raeder;
    public:
        Radfahrzeug(string bezeichnung, vector2d ort, int raeder);
        Radfahrzeug(const string& bezeichnung, int raeder);
        Radfahrzeug(const string& bezeichnung);
        Radfahrzeug(const Radfahrzeug& r);
        ~Radfahrzeug();
        //Radfahrzeug(string &n);
        int getRaeder() const;
        //bewegezu from superclass Verkehrsmittel
        string text() const;
};

#endif
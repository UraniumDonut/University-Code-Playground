#ifndef HEISSLUFTBALLON_H
#define HEISSLUFTBALLON_H

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "vector2d.h"
#include "Verkehrsmittel.h"
#include "Luftfahrzeug.h"

class Heissluftballon : public Luftfahrzeug{
    private:
        int volumen;
    public:
        Heissluftballon(string bezeichnung, vector2d ort, int volumen);
        Heissluftballon(string bezeichnung, int flughoehe, int volumen);
        Heissluftballon(const Heissluftballon& r);
        int getVolumen() const;
        string text() const;
};


#endif
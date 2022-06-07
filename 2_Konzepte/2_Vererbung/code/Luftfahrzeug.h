#ifndef LUFTFAHRZEUG_H
#define LUFTFAHRZEUG_H

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "vector2d.h"
#include "Verkehrsmittel.h"


class Luftfahrzeug : public Verkehrsmittel{
    private:
        int flughoehe;
    public:
        Luftfahrzeug(string bezeichnung, vector2d ort, int flughoehe);
        Luftfahrzeug(const string& bezeichnung, int flughoehe);
        Luftfahrzeug(const Luftfahrzeug& r);
        int maxFlughoehe() const;
        string text() const;
};

#endif
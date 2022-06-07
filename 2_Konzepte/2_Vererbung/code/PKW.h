#ifndef PKW_H
#define PKW_H

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "vector2d.h"
#include "Verkehrsmittel.h"
#include "Radfahrzeug.h"

class PKW : public Radfahrzeug{
    private:
        int tueren;
    public:
        PKW(string bezeichnung, vector2d ort, int raeder, int tueren);
        PKW(const string& bezeichnung, int tueren);
        PKW(const PKW& r);
        int getTueren() const;
        string text() const;
};

#endif
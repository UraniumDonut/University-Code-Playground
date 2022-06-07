#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "Verkehrsmittel.h"
#include "vector2d.h"
#include "Luftfahrzeug.h"

Luftfahrzeug::Luftfahrzeug(string bezeichnung, vector2d ort, int flughoehe):Verkehrsmittel(bezeichnung, ort), flughoehe(flughoehe){}
Luftfahrzeug::Luftfahrzeug(const string& bezeichnung, int flughoehe):Verkehrsmittel(bezeichnung), flughoehe(flughoehe){}
Luftfahrzeug::Luftfahrzeug(const Luftfahrzeug& r):Verkehrsmittel(r), flughoehe(r.flughoehe){}
int Luftfahrzeug::maxFlughoehe() const{return flughoehe;}
string Luftfahrzeug::text() const{
    stringstream s;
    s << Verkehrsmittel::name() << ": Position = " << Verkehrsmittel::position().text() << " Flughoehe = " << flughoehe;
    return s.str();
}


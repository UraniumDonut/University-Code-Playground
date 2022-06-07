#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "Verkehrsmittel.h"
#include "vector2d.h"
#include "Luftfahrzeug.h"
#include "Heissluftballon.h"

Heissluftballon::Heissluftballon(string bezeichnung, vector2d ort, int volumen):Luftfahrzeug(bezeichnung, ort, volumen){}
Heissluftballon::Heissluftballon(string bezeichnung, int flughoehe, int volumen):Luftfahrzeug(bezeichnung, flughoehe), volumen(volumen){}
Heissluftballon::Heissluftballon(const Heissluftballon& r):Luftfahrzeug(r), volumen(r.volumen) {}
int Heissluftballon::getVolumen() const{return volumen;}
string Heissluftballon::text() const{
    stringstream s;
    s << Luftfahrzeug::text() <<" Volumen = " << volumen;
    return s.str();
}
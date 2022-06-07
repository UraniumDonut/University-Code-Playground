#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "Verkehrsmittel.h"
#include "vector2d.h"
#include "Radfahrzeug.h"

Radfahrzeug::Radfahrzeug(string bezeichnung = "Radfahrzeug", vector2d ort= vector2d(0.0,0.0), int raeder=4):Verkehrsmittel(bezeichnung, ort), raeder(raeder){}
Radfahrzeug::Radfahrzeug(const string& bezeichnung, int raeder):Verkehrsmittel(bezeichnung), raeder(raeder){}
Radfahrzeug::Radfahrzeug(const string& bezeichnung):Verkehrsmittel(bezeichnung){
    raeder = 4;
}
Radfahrzeug::Radfahrzeug(const Radfahrzeug& r):Verkehrsmittel(r), raeder(r.raeder){}
Radfahrzeug::~Radfahrzeug(){cout << "Radfahrzeug " << Verkehrsmittel::name() << " wurde geloescht" << endl;}
int Radfahrzeug::getRaeder() const{return raeder;}
string Radfahrzeug::text() const{
    stringstream s;
    s << Verkehrsmittel::name() << ": Position = " << Verkehrsmittel::position().text() << " Raeder = " << raeder;
    return s.str();
}


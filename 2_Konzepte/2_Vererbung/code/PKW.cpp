#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "Verkehrsmittel.h"
#include "vector2d.h"
#include "Radfahrzeug.h"
#include "PKW.h"

PKW::PKW(string bezeichnung, vector2d ort, int raeder, int tueren):Radfahrzeug(bezeichnung, ort, raeder), tueren(tueren){}
PKW::PKW(const string& bezeichnung, int tueren):Radfahrzeug(bezeichnung), tueren(tueren){}
PKW::PKW(const PKW& r):Radfahrzeug(r), tueren(r.tueren){}
int PKW::getTueren() const{return tueren;}
string PKW::text() const{
    stringstream s;
    s << Radfahrzeug::text() <<" Tueren = " << tueren;
    return s.str();
}
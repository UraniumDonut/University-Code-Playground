#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "Verkehrsmittel.h"
#include "vector2d.h"

Verkehrsmittel::Verkehrsmittel(string bezeichnung, vector2d ort):bezeichnung(bezeichnung), ort(ort){}
Verkehrsmittel::Verkehrsmittel(const string& bezeichnung){
	this->bezeichnung = bezeichnung;
}
Verkehrsmittel::Verkehrsmittel(const Verkehrsmittel& v):bezeichnung(v.bezeichnung+"Kopie"), ort(v.ort){}
//Verkehrsmittel::Verkehrsmittel(string &n){ bezeichnung = n; vector2d o(0,0);ort = o;}	
string Verkehrsmittel::name() const{return bezeichnung;}
vector2d Verkehrsmittel::position() const{return ort;}
Verkehrsmittel::~Verkehrsmittel(){cout << "Verkehrsmittel " << bezeichnung << " wurde geloescht" << endl;}
void Verkehrsmittel::bewegezu(vector2d position){this->ort = position;}
string Verkehrsmittel::text() const{
	stringstream s;
	s <<bezeichnung << ": Position = " << ort.text();
		return s.str();
}



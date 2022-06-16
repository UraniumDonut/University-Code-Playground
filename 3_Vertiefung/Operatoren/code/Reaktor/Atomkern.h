#ifndef ATOMKERN_H
#define ATOMKERN_H


#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include <vector>
#include "Prueffolge.h"

using namespace std;

class Atomkern{
        
    public:
        string sym;
        int ord;
        int mas;

        //add Atomkern::PROTON as a static member
        static Atomkern PROTON;
        static Atomkern NEUTRON;
        static Atomkern HELIUM;

        Atomkern(string sym, int massenzahl, int ordnungszahl){
            this->sym = sym;
            this->ord = ordnungszahl;
            this->mas = massenzahl;
        }
        Atomkern(){
            this->sym = "";
            this->ord = 0;
            this->mas = 0;
        }
        Atomkern(int massenzahl, int ordnungszahl){
            this->sym = "";
            this->ord = ordnungszahl;
            this->mas = massenzahl;
        }
        string symbol() const{
            return sym;
        }
        int ordnungszahl() const{
            return ord;
        }
        int massenzahl() const{
            return mas;
        }
        //overload << operator
        friend ostream& operator<<(ostream& os, Atomkern& kern){
            os << kern.symbol() << "(" << kern.massenzahl() << "," << kern.ordnungszahl() << ")";
            return os;
        }
        //overload + operator
        Atomkern operator+(const Atomkern& kern) const{
            Atomkern kern2(kern.symbol(), kern.massenzahl()+this->mas, kern.ordnungszahl()+this->ord);
            return kern2;
        }
        //overload += operator
        Atomkern operator+=(Atomkern& kern){
            this->ord += kern.ordnungszahl();
            this->mas += kern.massenzahl();
            return *this;
        }
        //overload - operator
        Atomkern operator-(const Atomkern& kern) const{
            Atomkern kern2(kern.symbol(), this->mas - kern.massenzahl(), this->ord - kern.ordnungszahl());
            return kern2;
        }
        //overload -= operator
        Atomkern operator-=(const Atomkern& kern){
            this->ord -= kern.ordnungszahl();
            this->mas -= kern.massenzahl();
            return *this;
        }
        //overload == operator
        bool operator==(const Atomkern& kern){
            return (this->mas == kern.massenzahl() && this->ord == kern.ordnungszahl());
        }
        //overload * operator 
        Atomkern operator*(int i){
            Atomkern kern2(this->symbol(), this->mas*i, this->ord*i);
            return kern2;
        }
        string debug() const{
            stringstream ss;
            ss << "Atomkern(" << this->symbol() << "," << this->massenzahl() << "," << this->ordnungszahl() << ")";
            return ss.str();
        }
        //friend Atomkern operator*(int i, Atomkern& kern);
};

inline Atomkern operator*(int i, Atomkern& kern){
    Atomkern kern2(kern.symbol(), kern.massenzahl()*i, kern.ordnungszahl()*i);
    return kern2;
}



#endif //ATOMKERN_H 
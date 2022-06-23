#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include <vector>
#include "Atomkern.h"

using namespace std;


class Reaktor{
    public:
        
        Atomkern inhalt;


        Reaktor(){}

        Atomkern operator*() const{
            return this->inhalt;
        }
        //overload < adds an Atomkern to the Reaktor
        Reaktor operator<(Atomkern kern){
            this->inhalt += kern;
            return *this;
        }
        //overload > removes an Atomkern from the Reaktor
        Reaktor operator>(Atomkern kern){
            this->inhalt -= kern;
            return *this;
        }
        void operator~(){
            this->inhalt = Atomkern();
        }
        string debug() const{
            stringstream ss;
            ss << "Reaktor: " << (this->inhalt.debug());
            return ss.str();
        }

};
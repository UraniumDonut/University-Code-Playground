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


        //constructor with Atomkern("", 0, 0) as default
        Reaktor(){}

        Atomkern operator*() const{
            return this->inhalt;
        }
        //overload < adds an Atomkern to the Reaktor
        void operator<(Atomkern kern){
            this->inhalt += kern;
        }
        //overload > removes an Atomkern from the Reaktor
        void operator>(Atomkern kern){
            this->inhalt -= kern;
        }
        //overload ~ removes all Atomkerns from the Reaktor
        void operator~(){
            this->inhalt = Atomkern();
        }

};
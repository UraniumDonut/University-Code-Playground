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
        void operator<(Atomkern kern){
            this->inhalt += kern;
        }
        void operator>(Atomkern kern){
            this->inhalt -= kern;
        }
        void operator~(){
            this->inhalt = Atomkern();
        }

};
#ifndef SIRENE_H
#define SIRENE_H

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;


//class Sirene extends AlarmierbarImpl
class Sirene : public AlarmierbarImpl
{
    public:
        Sirene(string name) : AlarmierbarImpl(name) {}
        //constructor with random name
        Sirene() : AlarmierbarImpl("Sirene") {}
        void alarmieren();
};





#endif 
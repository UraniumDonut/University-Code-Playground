#ifndef SIRENE_H
#define SIRENE_H

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "main.cpp"

//Sirene extends AlarmierbarImpl
class Sirene : public AlarmierbarImpl{
    private:
        int anzahl;
    public:
        Sirene();
        void alarmieren();
        bool istAlarmiert();
        void alarmZuruecksetzen();
        string liefereName();
};


#endif
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "Sirene.h"


void Sirene::alarmieren()
{
    AlarmierbarImpl::alarmieren();
    Beep(1000, 1000);
}
#include "Atomkern.h"
Atomkern Atomkern::PROTON = Atomkern("H", 1, 1);
Atomkern Atomkern::NEUTRON = Atomkern("N", 1, 0);
Atomkern Atomkern::HELIUM = Atomkern("He", 2, 2);

//operator* 
/*Atomkern Atomkern::operator*(int i, Atomkern& kern){
    Atomkern kern2(kern.symbol(), kern.ordnungszahl()*i, kern.massenzahl()*i);
    return kern2;
}*/

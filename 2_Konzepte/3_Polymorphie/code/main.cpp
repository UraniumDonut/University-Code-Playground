#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "Alarmierbar.h"
using namespace std;


//interface Detektor
class Detektor
{
	public:
		virtual void anschliessen(Alarmierbar& alarmierbar) = 0;
		virtual void ausloesen() = 0;
		virtual ~Detektor() {}
};

class DetektorImpl : public Detektor
{
	private:
		string name;
		Alarmierbar* alarmierbar;
	public:
		DetektorImpl(string name)
		{
			this->name = name;
			alarmierbar = NULL;
		}
		void anschliessen(Alarmierbar& alarmierbar)
		{
			this->alarmierbar = &alarmierbar;
		}
		void ausloesen()
		{
			alarmierbar->alarmieren();
		}
};

class BewegungsDetektor : public DetektorImpl
{
	public:
		BewegungsDetektor(string name) : DetektorImpl(name) {}
		void anschliessen(Alarmierbar& alarmierbar)
		{
			DetektorImpl::anschliessen(alarmierbar);
		}
		void ausloesen()
		{
			DetektorImpl::ausloesen();
		}
};





int main()
{
	

	Sirene sirene("Sirene");
	BewegungsDetektor bewegungsDetektor("BewegungsDetektor");
	bewegungsDetektor.anschliessen(sirene);
	bewegungsDetektor.ausloesen();
}
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include <vector>
#include "Alarmierbar.h"
#include "vector2d.h"
using namespace std;


void alarmFuerAlleAnzeigen(vector<Alarmierbar *> *vA)
{
	for (Alarmierbar *e : *vA)
	{
		cout << e->liefereName() << ": Alarm ist ";
		if (e->istAlarmiert())
			cout << "an" << endl;
		else
			cout << "aus" << endl;
	}
}

void alarmFuerAlleZuruecksetzen(vector<Alarmierbar *> *vA)
{
	for (Alarmierbar *e : *vA)
	{
		e->alarmZuruecksetzen();
	}
}

//interface Detektor
class Detektor
{
	public:
		virtual void anschliessen(Alarmierbar &) = 0;
		virtual void ausloesen() = 0;
		virtual ~Detektor() = default;
};

class DetektorImpl : public Detektor
{
	private:
		string name;
		vector<Alarmierbar *> angeschlossen;
		Alarmierbar *alarmierbar;
	public:
		DetektorImpl(string name)
		{
			this->name = name;
		}
		void anschliessen(Alarmierbar &alarmierbar)
		{
			angeschlossen.push_back(&alarmierbar);
    		this->alarmierbar = &alarmierbar;

    		cout << alarmierbar.liefereName() << " an "<< name << " aschliessen" << endl;
		}
		void alarmieren()
		{
			for (Alarmierbar *e : angeschlossen)
    		{
        		e->alarmieren();
    		}
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
			DetektorImpl::alarmieren();
			
		}
};

class GerauschDetektor : public DetektorImpl
{
	public:
		GerauschDetektor(string name) : DetektorImpl(name) {}
		void anschliessen(Alarmierbar& alarmierbar)
		{
			DetektorImpl::anschliessen(alarmierbar);
		}
		void ausloesen()
		{
			DetektorImpl::alarmieren();
		}
};





int main()
{
	cout << "*** Alarmsystem aufbauen\n";

 	vector<Alarmierbar*> vectorAlarmierbar;
 	Detektor* detektor[2];
	detektor[0] = new BewegungsDetektor("BD1");
	Sirene sirene;
	vectorAlarmierbar.push_back(&sirene);

	int lumen = 5000;
	const int N_FLUTLICHT = 3;
	Flutlicht* flutlicht[N_FLUTLICHT];
	for (int i = 0; i < N_FLUTLICHT; i++)
	{
		flutlicht[i] = new Flutlicht(lumen * (i + 1));
		vectorAlarmierbar.push_back(flutlicht[i]);
		detektor[0]->anschliessen(*flutlicht[i]);
	}
	detektor[1] = new GerauschDetektor("GD1");
	detektor[1]->anschliessen(sirene);
	detektor[1]->anschliessen(*flutlicht[1]);

	cout << "*** Alarmsystem testen\n";

	detektor[0]->ausloesen();
	alarmFuerAlleAnzeigen(&vectorAlarmierbar);
	alarmFuerAlleZuruecksetzen(&vectorAlarmierbar);
	alarmFuerAlleAnzeigen(&vectorAlarmierbar);

	detektor[1]->ausloesen();
	alarmFuerAlleAnzeigen(&vectorAlarmierbar);

	cout << "*** Alarmsystem zerstoeren\n";
	delete detektor[0];
	delete detektor[1];
	for (auto f : flutlicht)
	{
		delete f;
	}
}
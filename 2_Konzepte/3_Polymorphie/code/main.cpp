#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>


using namespace std;

//Implicit class AlarmierbarImpl
class AlarmierbarImpl
{
	private:
		bool active;
	public:
		AlarmierbarImpl(){
			active = false;
		}
		void alarmieren(){
			cout << "AlarmierbarImpl::alarmieren()" << endl;
			active = true;
		}
		bool istAlarmiert(){
			cout << "AlarmierbarImpl::istAlarmiert()" << endl;
			return active;
		}
		void alarmZuruecksetzen(){
			cout << "AlarmierbarImpl::alarmZuruecksetzen()" << endl;
			active = false;
		}

};

int main() {
	AlarmierbarImpl a;
	a.alarmieren();
	assert(a.istAlarmiert());
	a.alarmZuruecksetzen();
	assert(!a.istAlarmiert());
	return 0;


}



/*
int main() {
	cout << "*** Alarmsystem aufbauen\n";
	
	vector<Alarmierbar*> vectorAlarmierbar;
	Detektor* detektor[2];
	
	detektor[0] = new BewegungsDetektor("BD1");

	Sirene sirene;
	vectorAlarmierbar.push_back(&sirene);
	detektor[0]->anschliessen(sirene);

	int lumen = 5000;
	const int N_FLUTLICHT = 3;
	Flutlicht* flutlicht[N_FLUTLICHT];
	for(int i=0; i<N_FLUTLICHT; i++) {
		flutlicht[i] = new Flutlicht(lumen*(i+1));
		vectorAlarmierbar.push_back(flutlicht[i]);
		detektor[0]->anschliessen(*flutlicht[i]);
	}
	detektor[1] = new GeraeuschDetektor("GD1");
	detektor[1]->anschliessen(sirene);
	detektor[1]->anschliessen(*flutlicht[1]);

	cout << "*** Alarmsystem testen\n";
	detektor[0]->ausloesen();
	alarmFuerAlleAnzeigen(&vectorAlarmierbar);
	alarmFuerAlleZuruecksetzen(&vectorAlarmierbar);
	alarmFuerAlleAnzeigen(&vectorAlarmierbar);
	detektor[1]->ausloesen();
	alarmFuerAlleAnzeigen(&vectorAlarmierbar);
	
	cout << "*** Alarmsystem abbauen\n";
	delete detektor[0];
	delete detektor[1];
	for(auto f : flutlicht) {
		delete f;
	}
}
*/
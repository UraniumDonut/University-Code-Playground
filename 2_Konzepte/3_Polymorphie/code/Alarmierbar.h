#ifndef ALARMIERBAR_H
#define ALARMIERBAR_H

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;


//class interface Alarmierbar
class Alarmierbar
{
	public:
		virtual void alarmieren() = 0;
		virtual string liefereName() = 0;
		virtual bool istAlarmiert() = 0;
		virtual void alarmZuruecksetzen() = 0;
		virtual ~Alarmierbar() {}
};

//AlarmierbarImpl extends Alarmierbar
class AlarmierbarImpl : public Alarmierbar
{
	public:
	string name;
		bool alarmiert;
		AlarmierbarImpl(string name)
		{
			this->name = name;
			alarmiert = false;
		}
		AlarmierbarImpl(){
			stringstream ss;
			ss << "Alarmierbar " << rand() % 100;
			this->name = ss.str();
			alarmiert = false;
		}
		void alarmieren()
		{
			cout << "Ich wurde alarmiert!!!" << endl;
			alarmiert = true;
		}
		string liefereName()
		{
			return name;
		}
		bool istAlarmiert()
		{
			return alarmiert;
		}
		void alarmZuruecksetzen()
		{
			alarmiert = false;
		}
};

class Sirene : public AlarmierbarImpl
{
	public:
		Sirene(string name) : AlarmierbarImpl(name) {}
		Sirene() : AlarmierbarImpl() {
			stringstream ss;
			ss << "Sirene " << rand() % 100;
			this->name = ss.str();
		}
		void alarmieren(){
			
			MessageBeep(MB_OK);  
			AlarmierbarImpl::alarmiert = true;
			cout << "Sirene: " << name << " wurde alarmiert!  Heul!" << endl;
		}
};

class Flutlicht : public AlarmierbarImpl
{
	public:
		int brightness;
		Flutlicht(string name) : AlarmierbarImpl(name) { brightness = 123; }
		Flutlicht(int brightness) : AlarmierbarImpl() {
			stringstream ss;
			ss << "Flutlicht " << rand() % 100;
			this->name = ss.str();
			this->brightness = brightness;
		}
		Flutlicht() : AlarmierbarImpl() {
			stringstream ss;
			ss << "Flutlicht " << rand() % 100;
			this->brightness = 123;
			this->name = ss.str();
		}
		void alarmieren(){
			
			MessageBeep(MB_OK);  
			AlarmierbarImpl::alarmiert = true;
			cout << "Flutlicht: " << name << " wurde alarmiert! Mit " << brightness << " Helligkeit!" << endl;
		}
		void setBrightness(int brightness){
			this->brightness = brightness;
		}
};




#endif // ALARMIERBAR_H
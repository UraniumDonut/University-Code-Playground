#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <windows.h>
#include "vector2d.h"
#include "Verkehrsmittel.h"
#include "Radfahrzeug.h"
#include "Luftfahrzeug.h"
#include "PKW.h"
#include "Heissluftballon.h"
using namespace std;

/*int main(){
	vector2d v1(1.0,2.0);
	Verkehrsmittel v2("Generisch", v1);
	Verkehrsmittel v3("Generisch2", v1);
	Radfahrzeug r1("Radfahrzeug", v1, 4);
	Luftfahrzeug l1("Luftfahrzeug", v1, 10);
	PKW p1("PKW", v1, 4, 5);
	Heissluftballon h1("Heissluftballon", v1, 10);
	cout << v2.text() << endl;
	cout << v3.text() << endl;
	cout << r1.text() << endl;
	cout << l1.text() << endl;
	cout << p1.text() << endl;
	cout << h1.text() << endl;
}*/

void test01()
{
	cout << "test01:\n-------\n";
	const Verkehrsmittel verkehrsmittel("Verkehrsmittel");
	const Radfahrzeug radfahrzeug("Radfahrzeug", 3);
	const PKW pkw("VW Käfer", 2);
	const Luftfahrzeug luftfahrzeug("Luftfahrzeug", 10000);
	const Heissluftballon heissluftballon("Heissluftballon", 500, 7500);

	cout << verkehrsmittel.text() << endl;
	cout << radfahrzeug.text() << endl;
	cout << pkw.text() << endl;
	cout << luftfahrzeug.text() << endl;
	cout << heissluftballon.text() << endl;
	assert(radfahrzeug.getRaeder() == 3);
	assert(pkw.name() == "VW Käfer");
	assert(pkw.getRaeder() == 4);
	assert(pkw.getTueren() == 2);
	assert(heissluftballon.maxFlughoehe() == 500);
	assert(heissluftballon.getVolumen() == 7500);
}

void test02()
{
	cout << "test02:\n-------\n";
	PKW pkw("PKW", 2);
	cout << pkw.text() << endl;
	pkw.bewegezu(vector2d(50, 60));
	cout << pkw.text() << endl;
	cout << pkw.name() << " befindet sich nach der Bewegung an Position " << pkw.position().text() << endl;
	assert(pkw.position().x == 50);
	assert(pkw.position().y == 60);
	Heissluftballon heissluftballon("Heissluftballon", 1000, 7500);
	cout << heissluftballon.text() << endl;
	heissluftballon.bewegezu(vector2d(70, 80));
	cout << heissluftballon.name() << " befindet sich nach der Bewegung an Position " << heissluftballon.position().text() << endl;
	assert(heissluftballon.position().x == 70);
	assert(heissluftballon.position().y == 80);
}

void test03()
{
	cout << "test03:\n-------\n";
	PKW pkw1("PKW1", 5);
	pkw1.bewegezu(vector2d(77, 88));
	cout << pkw1.text() << endl;
	const PKW pkw2 = pkw1;
	cout << pkw2.text() << endl;
	assert(pkw1.getRaeder() == pkw2.getRaeder());
	assert(pkw1.getTueren() == pkw2.getTueren());
	assert(pkw1.position().x == pkw2.position().x);
	assert(pkw1.position().y == pkw2.position().y);
	assert(pkw1.name() != pkw2.name());
}

void test04()
{
	cout << "test04:\n-------\n";
	Heissluftballon ballon1("Ballon1", 234, 5678);
	ballon1.bewegezu(vector2d(99, 111));
	cout << ballon1.text() << endl;
	const Heissluftballon ballon2{ballon1};
	cout << ballon2.text() << endl;

	assert(ballon1.maxFlughoehe() == ballon2.maxFlughoehe());
	assert(ballon1.getVolumen() == ballon2.getVolumen());
	assert(ballon1.position().x == ballon2.position().x);
	assert(ballon1.position().y == ballon2.position().y);
	assert(ballon1.name() != ballon2.name());
}

int main()
{
	test01();
	cout << endl;
	test02();
	cout << endl;
	test03();
	cout << endl;
	test04();
	cout << endl;
}

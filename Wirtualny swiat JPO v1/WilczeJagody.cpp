#include "stdafx.h"
#include "WilczeJagody.h"
 
char WilczeJagody::rysowanie() {
	return ';';
}

void WilczeJagody::reakcja(Organizm * napastnik) {
	this->zabij(napastnik);
}

WilczeJagody::WilczeJagody(int x, int y, Swiat *swiat) {
	setPolozenieX(x);
	setPolozenieY(y);
	setCzyReakcja(true);
	setZywy(true);
	setRobilRuch(true);
	setSwiat(swiat);
	setSila(0);
	setInicjatywa(0);
	setGatunek("Wilcze jagody");
	setCzasZycia(0);
	setId(swiat->getIloscOrganizmow());
	swiat->setDiffIloscOrganizmowAktualna(1);
	swiat->setIloscOrganizmowPlus1();
}

WilczeJagody::~WilczeJagody() {
}

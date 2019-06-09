#include "stdafx.h"
#include "Kret.h"

char Kret::rysowanie() {
	return 'k';
}

void Kret::akcja() {
	int nowyX = this->losujX();
	int nowyY = this->losujY();
	if (!this->_swiat->czyWolne(nowyX, nowyY)) this->kolizja(nowyX, nowyY);
	if (this->getCzyZywy()) this->zmienPoleNa(nowyX, nowyY);
}

Kret::Kret(int x, int y, Swiat *swiat) {
	setPolozenieX(x);
	setPolozenieY(y);
	setCzyReakcja(false);
	setZywy(true);
	setRobilRuch(true);
	setSwiat(swiat);
	setSila(2);
	setInicjatywa(3);
	setGatunek("Kret");
	setCzasZycia(0);
	setId(swiat->getIloscOrganizmow());
	swiat->setDiffIloscOrganizmowAktualna(1);
	swiat->setIloscOrganizmowPlus1();
}

Kret::~Kret() {
}

int Kret::losujX() {
	return rand() % this->getSwiat()->getRozmiarX();
}

int Kret::losujY() {
	return rand() % this->getSwiat()->getRozmiarY();
}
#include "stdafx.h"
#include "Wilk.h"

char Wilk::rysowanie() {
	return 'w';
}

Wilk::Wilk(int x, int y, Swiat *swiat) {
	setPolozenieX(x);
	setPolozenieY(y);
	setCzyReakcja(false);
	setZywy(true);
	setRobilRuch(true);
	setSwiat(swiat);
	setSila(9);
	setInicjatywa(5);
	setGatunek("Wilk");
	setCzasZycia(0);
	setId(swiat->getIloscOrganizmow());
	swiat->setDiffIloscOrganizmowAktualna(1);
	swiat->setIloscOrganizmowPlus1();
}

Wilk::~Wilk() {
}
#include "stdafx.h"
#include "Trawa.h"

char Trawa::rysowanie() {
	return '_';
}

Trawa::Trawa(int x, int y, Swiat *swiat) {
	setPolozenieX(x);
	setPolozenieY(y);
	setCzyReakcja(false);
	setZywy(true);
	setRobilRuch(true);
	setSwiat(swiat);
	setSila(0);
	setInicjatywa(0);
	setGatunek("Trawa");
	setCzasZycia(0);
	setId(swiat->getIloscOrganizmow());
	swiat->setDiffIloscOrganizmowAktualna(1);
	swiat->setIloscOrganizmowPlus1();
}

Trawa::~Trawa() {
}

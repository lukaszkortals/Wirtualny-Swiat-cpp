#include "stdafx.h"
#include "Owca.h"


char Owca::rysowanie() {
	return 'o';
}

Owca::Owca(int x, int y, Swiat *swiat) {
	setPolozenieX(x);
	setPolozenieY(y);
	setCzyReakcja(false);
	setZywy(true);
	setRobilRuch(true);
	setSwiat(swiat);
	setSila(4);
	setInicjatywa(4);
	setGatunek("Owca");
	setCzasZycia(0);
	setId(swiat->getIloscOrganizmow());
	swiat->setDiffIloscOrganizmowAktualna(1);
	swiat->setIloscOrganizmowPlus1();
}

Owca::~Owca() {
}

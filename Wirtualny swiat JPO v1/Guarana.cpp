#include "stdafx.h"
#include "Guarana.h"

char Guarana::rysowanie() {
	return '*';
}

void Guarana::reakcja(Organizm * napastnik) {
	napastnik->setSila(napastnik->getSila() + 3);
}

Guarana::Guarana(int x, int y, Swiat *swiat) {
	setPolozenieX(x);
	setPolozenieY(y);
	setCzyReakcja(true);
	setZywy(true);
	setRobilRuch(true);
	setSwiat(swiat);
	setSila(0);
	setInicjatywa(0);
	setGatunek("Guarana");
	setCzasZycia(0);
	setId(swiat->getIloscOrganizmow());
	swiat->setDiffIloscOrganizmowAktualna(1);
	swiat->setIloscOrganizmowPlus1();
}

Guarana::~Guarana() {
}
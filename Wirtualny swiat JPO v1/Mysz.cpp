#include "stdafx.h"
#include "Mysz.h"

void Mysz::probaUcieczni(Organizm* oponent) {
	int nowyX = this->losujPrzesuniecieX();
	int nowyY = this->losujPrzesuniecieY();
	if (this->getSwiat()->czyWolne(nowyX, nowyY)) {
		
		string noweZdarzenie = this->getGatunek() + " z [" + to_string(this->getPolozenieX() + 1) + " , " + to_string(this->getPolozenieY() + 1) + "] ucieka przed " + oponent->getGatunek() + " na [" + to_string(nowyX + 1) + " , " + to_string(nowyY + 1) + "]\n";
		this->zmienPoleNa(nowyX, nowyY);
		this->getSwiat()->getHistoriaSwiata()->dodajZdarzenie(noweZdarzenie);
	}
}

void Mysz::reakcja(Organizm * napastnik) {
	probaUcieczni(napastnik);
}

char Mysz::rysowanie() {
	return 'm';
}

void Mysz::kolizja(int drugiX, int drugiY) {
	Organizm *atakowany = this->_swiat->getOrganizmPoXiY(drugiX, drugiY);
	if (this == atakowany) return;
	if (this->getGatunek() == atakowany->getGatunek()) {
		this->rozmnarzanie(atakowany);
	}
	else {
		int myszSila = this->getSila();
		int atakowanySila = atakowany->getSila();
		if (atakowany->getInicjatywa() == 0) this->zjedz(atakowany);
		else if (this < atakowany) this->probaUcieczni(atakowany);
		else this->zabij(atakowany);
	}
}

Mysz::Mysz(int x, int y, Swiat *swiat) {
	setPolozenieX(x);
	setPolozenieY(y);
	setCzyReakcja(true);
	setZywy(true);
	setRobilRuch(true);
	setSwiat(swiat);
	setSila(1);
	setInicjatywa(6);
	setGatunek("Mysz");
	setCzasZycia(0);
	setId(swiat->getIloscOrganizmow());
	swiat->setDiffIloscOrganizmowAktualna(1);
	swiat->setIloscOrganizmowPlus1();
}

Mysz::~Mysz() {
}

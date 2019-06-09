#include "stdafx.h"
#include "Lis.h"

char Lis::rysowanie() {
	return 'l';
}

void Lis::akcja() {
	int losX = this->losujPrzesuniecieX();
	int losY = this->losujPrzesuniecieY();
	int nowyX = losX;
	int nowyY = losY;
	if (!this->_swiat->czyWolne(nowyX, nowyY)) {
		Organizm *atakowany = this->getSwiat()->getOrganizmPoXiY(nowyX, nowyY);
		if (atakowany == this) return;
		if (*atakowany > *this) {
			string noweZdarzenie = this->getGatunek() + " z [" + to_string(this->getPolozenieX()+1) + " , "+ to_string(this->getPolozenieY()+1)  +"] odpuszcza atak na " + atakowany->getGatunek() + " w [" + to_string(atakowany->getPolozenieX()+1) + " , " + to_string(atakowany->getPolozenieY()+1) + "]\n";
			this->getSwiat()->getHistoriaSwiata()->dodajZdarzenie(noweZdarzenie);
		}
		else this->kolizja(nowyX, nowyY);
	}
	if (this->getCzyZywy()) this->zmienPoleNa(nowyX, nowyY);
}

Lis::Lis(int x, int y, Swiat *swiat) {
	setPolozenieX(x);
	setPolozenieY(y);
	setCzyReakcja(false);
	setZywy(true);
	setRobilRuch(true);
	setSwiat(swiat);
	setSila(3);
	setInicjatywa(7);
	setGatunek("Lis");
	setCzasZycia(0);
	setId(swiat->getIloscOrganizmow());
	swiat->setDiffIloscOrganizmowAktualna(1);
	swiat->setIloscOrganizmowPlus1();
}

Lis::~Lis() {
}
